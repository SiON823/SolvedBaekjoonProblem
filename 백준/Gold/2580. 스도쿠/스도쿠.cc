#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int board[9][9];

void sudoku(int n) {
	if (n == 81) {
		for (int i = 0; i < 9; i++) {
			printf("%d %d %d %d %d %d %d %d %d\n", board[i][0], board[i][1], board[i][2], board[i][3], board[i][4], board[i][5], board[i][6], board[i][7], board[i][8]);
		}
		exit(0);
	}
	else {
		int cols = n / 9;
		int rows = n % 9;
		
		if (board[cols][rows] != 0) {
			sudoku(n + 1);
		}
		else {
			for (int i = 1; i <= 9; i++) {
				board[cols][rows] = i;
				int f = 0;

				for (int j = 0; j < 9; j++) {
					if (j != rows && board[cols][j] == i) f = 1;
					if (j != cols && board[j][rows] == i) f = 1;
				}

				int ccols = 0;
				int crows = 0;
				for (int k1 = 1; k1 <= 7; k1 += 3) {
					for (int k2 = 1; k2 <= 7; k2 += 3) {
						if (abs(k1 - cols) <= 1 && abs(k2 - rows) <= 1) {
							ccols = k1;
							crows = k2;
						}
					}
				}

				for (int num1 = ccols - 1; num1 <= ccols + 1; num1++) {
					for (int num2 = crows - 1; num2 <= crows + 1; num2++) {
						if (num1 == cols && num2 == rows)
							continue;
						else {
							if (board[num1][num2] == i)
								f = 1;
						}
					}
				}

				if (!f) {
					sudoku(n + 1);
				}
				board[cols][rows] = 0;
			}
		}
	}

}

int main() {
	for (int i = 0; i < 9; i++) {
		scanf("%d %d %d %d %d %d %d %d %d", &board[i][0], &board[i][1], &board[i][2], &board[i][3], &board[i][4], &board[i][5], &board[i][6], &board[i][7], &board[i][8]);
	}
	sudoku(0);

}