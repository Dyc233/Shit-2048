#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
#define PICS 11

int cantMove();
int emptyCount();
int move(char);
int up();
int down();
int left();
int right();
void playSound(int);
void printBoard();
void end();

int board[4][4] = {};
int empty[16][2] = {};
int twoFour[5] = { 2,2,2,2,4 };
int score_, step_ = 0;

int main(void) {
	//游戏预加载
	int emp = 0;
	board[0][0] = 2;
	printBoard();
	printf("\n\n      2048小游戏V1.0    ");
	printf("\n使用wasd控制上下左右的移动");
	printf("\n达到5000分数可获取随机奖励");
	printf("\n合成出2048可约作者线下PVP ");
	printf("\n              BY Anko_6go ");
	printf("\n                2023.4.14 ");

	//游戏运行逻辑
	while (1) {
		if (!emptyCount())
			if (cantMove())
				break;

		int moveFlag = 0;
		while (!moveFlag) {
			char key = _getch();
			moveFlag = move(key);
		}

		srand((unsigned int)time(NULL));
		playSound(rand()%9+1);
		step_++;

		emp = emptyCount();
		int r = rand() % emp, _r = rand() % 5;
		int _y = empty[r][0], _x = empty[r][1];
		board[_y][_x] = twoFour[_r];

		system("cls");
		printBoard();
	}
	end();
	system("pause");

	return 0;
}

int emptyCount(void) {
	int i = 0;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (!board[y][x]) {
				empty[i][0] = y;
				empty[i][1] = x;
				i++;
			}
		}
	}

	return i;
}

int move(char dr) {
	switch (dr) {
	case'w':
		return up();
	case'a':
		return left();
	case's':
		return down();
	case'd':
		return right();
	default:
		return 0;
	}
}

int cantMove(void) {
	for (int i = 0; i < 4; i++){
		int t1 = 0, t2 = 1;
		while (t2 <= 3){
			if (board[i][t1] == board[i][t2] || board[t1][i] == board[t2][i]){
				return 0;
			}
			else{
				t1++;
				t2++;
			}
		}
	}
	return 1;
}

int right(void) {
	int FLAG = 1;
	int x, y;
	int F = 0;

	while (FLAG) {
		FLAG = 0;
		for (y = 0; y <= 3; y++) {
			for (x = 0; x < 3; x++) {
				if (!board[y][x]) continue;
				if (!board[y][x + 1]) {
					board[y][x + 1] = board[y][x];
					board[y][x] = 0;
					FLAG = 1;
					F = 1;
				}
				else {
					if (board[y][x + 1] == board[y][x]) {
						board[y][x + 1] *= 2;
						board[y][x] = 0;
						FLAG = 1;
						F = 1;
						score_ += board[y][x + 1];
					}
					else continue;
				}
			}
		}
	}

	return F;
}

int left(void) {
	int FLAG = 1;
	int x, y;
	int F = 0;

	while (FLAG) {
		FLAG = 0;
		for (y = 0; y <= 3; y++) {
			for (x = 3; x > 0; x--) {
				if (!board[y][x]) continue;
				if (!board[y][x - 1]) {
					board[y][x - 1] = board[y][x];
					board[y][x] = 0;
					FLAG = 1;
					F = 1;
				}
				else {
					if (board[y][x - 1] == board[y][x]) {
						board[y][x - 1] *= 2;
						board[y][x] = 0;
						FLAG = 1;
						F = 1;
						score_ += board[y][x - 1];
					}
					else continue;
				}
			}
		}
	}

	return F;
}

int up(void) {
	int FLAG = 1;
	int x, y;
	int F = 0;

	while (FLAG) {
		FLAG = 0;
		for (x = 0; x <= 3; x++) {
			for (y = 3; y > 0; y--) {
				if (!board[y][x]) continue;
				if (!board[y-1][x]) {
					board[y-1][x] = board[y][x];
					board[y][x] = 0;
					FLAG = 1;
					F = 1;
				}
				else {
					if (board[y-1][x] == board[y][x]) {
						board[y-1][x] *= 2;
						board[y][x] = 0;
						FLAG = 1;
						F = 1;
						score_ += board[y-1][x];
					}
					else continue;
				}
			}
		}
	}

	return F;
}

int down(void) {
	int FLAG = 1;
	int x, y;
	int F = 0;

	while (FLAG) {
		FLAG = 0;
		for (x = 0; x <= 3; x++) {
			for (y = 0; y < 3; y++) {
				if (!board[y][x]) continue;
				if (!board[y + 1][x]) {
					board[y + 1][x] = board[y][x];
					board[y][x] = 0;
					FLAG = 1;
					F = 1;
				}
				else {
					if (board[y + 1][x] == board[y][x]) {
						board[y + 1][x] *= 2;
						board[y][x] = 0;
						FLAG = 1;
						F = 1;
						score_ += board[y + 1][x];
					}
					else continue;
				}
			}
		}
	}

	return F;
}

void printBoard(void) {
	int x, y;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			switch (board[y][x]) {
				case 0:
					SetConsoleTextAttribute(hConsole,240);
					break;
				case 2:
					SetConsoleTextAttribute(hConsole, 112);
					break;
				case 4:
					SetConsoleTextAttribute(hConsole, 128);
					break;
				case 8:
					SetConsoleTextAttribute(hConsole, 224);
					break;
				case 16:
					SetConsoleTextAttribute(hConsole, 96);
					break;
				case 32:
					SetConsoleTextAttribute(hConsole, 176);
					break;
				case 64:
					SetConsoleTextAttribute(hConsole, 48);
					break;
				case 128:
					SetConsoleTextAttribute(hConsole, 144);
					break;
				case 256:
					SetConsoleTextAttribute(hConsole, 16);
					break;
				case 512:
					SetConsoleTextAttribute(hConsole, 160);
					break;
				case 1024:
					SetConsoleTextAttribute(hConsole, 32);
					break;
				case 2048:
					SetConsoleTextAttribute(hConsole, 192);
					break;
				case 4096:
					SetConsoleTextAttribute(hConsole, 64);
					break;
				case 8192:
					SetConsoleTextAttribute(hConsole, 208);
					break;
				case 16384:
					SetConsoleTextAttribute(hConsole, 80);
					break;
				case 32768:
					SetConsoleTextAttribute(hConsole, 15);
					break;
			}
			printf("%-6d", board[y][x]);
		}
		printf("\n");
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf("\nSTEP %-10dSCORE %-8d", step_, score_);
}

void playSound(int i) {
	switch (i) {
		case 1:
			PlaySound(TEXT(".\\sounds\\s1.wav"), NULL, SND_FILENAME | SND_ASYNC);
			break;
		case 2:
			PlaySound(TEXT(".\\sounds\\s2.wav"), NULL, SND_FILENAME | SND_ASYNC);
			break;		
		case 3:
			PlaySound(TEXT(".\\sounds\\s3.wav"), NULL, SND_FILENAME | SND_ASYNC);
			break;
		case 4:
			PlaySound(TEXT(".\\sounds\\s4.wav"), NULL, SND_FILENAME | SND_ASYNC);
			break;
		case 5:
			PlaySound(TEXT(".\\sounds\\s5.wav"), NULL, SND_FILENAME | SND_ASYNC);
			break;
		case 6:
			PlaySound(TEXT(".\\sounds\\s6.wav"), NULL, SND_FILENAME | SND_ASYNC);
			break;
		case 7:
			PlaySound(TEXT(".\\sounds\\s7.wav"), NULL, SND_FILENAME | SND_ASYNC);
			break;
		case 8:
			PlaySound(TEXT(".\\sounds\\s8.wav"), NULL, SND_FILENAME | SND_ASYNC);
			break;
		case 9:
			PlaySound(TEXT(".\\sounds\\s9.wav"), NULL, SND_FILENAME | SND_ASYNC);
			break;
	}
}

void end(void) {
	system("cls");
	printBoard();
	printf("\n\n       GAME OVER!\n");
	if (score_ >= 5000) {
		int ch;
		printf("\n恭喜你解锁了高分奖励！");
		printf("\n请在确认周围没人之后，按F获得你的奖励\n或者按其他任意键退出游戏。");
		while (ch = _getch()) {
			if (ch == 'f') {
				srand((unsigned int)time(NULL));
				char pic[20];
				int picN = rand() % PICS + 1;
				sprintf_s(pic, ".\\pictures\\p%d.jpg", picN);
				system(pic);
				printf("\n什么，不够涩？按F再换一张！");
				continue;
			}
			else break;
		}
	}
}
