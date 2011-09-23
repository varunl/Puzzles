#include <stdio.h>

int queens(int board[8][8], int col, int *sum);
int removePlaces(int board[8][8], int row, int col);
int unremovePlace(int board[8][8], int row, int col);

int main() {
	int board[8][8];
	int i, j;

	//initialize board
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			board[i][j] = 0;
		}
	}

	int result;
	int sum = 0;
	result = queens(board, 0, &sum);
	printf("result = %d\n", sum);
}

int queens(int board[8][8], int col, int *sum) {
	if (col == 8) (*sum)++;
	int i;
	int check = 0;
	for (i = 0; i < 8; i++) {
		if (board[i][col] == 0) {
			board[i][col] = 9; 
			removePlaces(board, i, col);
			check = queens(board, col + 1, sum);
			board[i][col] = 0;
			unremovePlaces(board, i, col);
		}
	}
	return 0;
}

int removePlaces(int board[8][8], int row, int col) {
	int i, j = 1;
	for (i = col + 1; i < 8; i++) {
		if (row - j >= 0) {
			board[row - j][i]++;
		}
		if (row + j < 8) {
			board[row + j][i]++;
		}
		board[row][i]++;
		j++;
	}
}

int unremovePlaces(int board[8][8], int row, int col) {
	int i, j = 1;
	for (i = col + 1; i < 8; i++) {
		if (row - j >= 0) {
			board[row - j][i]--;
		}
		if (row + j < 8) {
			board[row + j][i]--;
		}
		board[row][i]--;
		j++;
	}
}
