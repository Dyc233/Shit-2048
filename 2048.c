#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

int set2or4();
//int cantMove();
int move(char);
int score();
int up();
int down();
int left();
int right();
void printBoard();

int board[4][4] = {};
int twoFour[5] = { 2,2,2,2,4 };
int score_, step_ = 0;

int main(void) {
	set2or4();
	printBoard();
	while (1) {
		int moveFlag = 0;
		while (!moveFlag) {
			char key = _getch();
			moveFlag = move(key);
		}
		score_ = score();
		step_++;
		if (!set2or4()) break;

		system("cls");
		printBoard();
	}

	printf("\nEND");

	return 0;
}

int set2or4(void) {
	int FLAG = 0;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (!board[y][x])
				FLAG = 1;
		}
	}
	if (!FLAG) return 0;

	int _x, _y, r;
	while (1) {
		srand((unsigned int)time(NULL));
		_x = rand() % 4;
		_y = rand() % 4;
		r = rand() % 5;
		if (board[_y][_x] == 0) {
			board[_y][_x] = twoFour[r];
			return 1;
		}
		else continue;
	}
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
					}
					else continue;
				}
			}
		}
	}

	return F;
}

int score(void) {
	int s = 0;
	int x, y;
	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			s += board[y][x];
		}
	}

	return s;
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
	printf("\nSTEP %-12dSCORE %-8d", step_, score_);
}
