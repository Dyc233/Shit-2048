#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

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
	system("color F8");
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
	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			printf("%-8d", board[y][x]);
		}
		printf("\n\n");
	}
	printf("\n\nSTEP %-16dSCORE %-8d", step_, score_);
}
