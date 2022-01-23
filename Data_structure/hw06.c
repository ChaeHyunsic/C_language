#include <stdio.h>
#include <stdlib.h>

#define N   0
#define NE  1
#define E   2
#define SE  3
#define S   4
#define SW  5
#define W   6
#define NW  7

typedef struct _Infor {
	int x;
	int y;
}Infor;

Infor create_infor(int x, int y) {
	Infor tmp_infor;

	tmp_infor.x = x;
	tmp_infor.y = y;

	return tmp_infor;
}

int** create_mark(int** mark, int row, int col) {
	int** result_mark;
	int i, j, k;

	result_mark = (int**)malloc(sizeof(int*) * row);
	for (i = 0; i < row; i++) {
		result_mark[i] = (int*)malloc(sizeof(int) * col);
	}

	for (j = 0; j < row; j++) {
		for (k = 0; k < col; k++) {
			result_mark[j][k] = mark[j][k];
		}
	}

	return result_mark;
}

int creat_top(int* top) {
	int result_top;

	result_top = *top + 1;

	return result_top;
}

void free_mark(int** result_mark, int row) {
	int i;

	for (i = 0; i < row; i++) {
		free(result_mark[i]);
	}
	free(result_mark);
}

int move(int** maze, int** mark, int row, int col, Infor* stack, int* top) {
	int sum = 0, count = 0;
	Infor tmp_infor;
	int i;

	if (stack[*top].x == col - 2 && stack[*top].y == row - 2) {
		return 1;
	}

	for (i = 0; i < 8; i++) {
		tmp_infor = create_infor(stack[*top].x, stack[*top].y);

		if (i == NW || i == N || i == NE)
			tmp_infor.x -= 1;
		else if (i == SE || i == S || i == SW)
			tmp_infor.x += 1;
		if (i == NE || i == E || i == SE)
			tmp_infor.y += 1;
		else if (i == SW || i == W || i == NW)
			tmp_infor.y -= 1;

		if (maze[tmp_infor.y][tmp_infor.x] == 0 && mark[tmp_infor.y][tmp_infor.x] == 0) {
			int** result_mark, result_top;

			result_mark = create_mark(mark, row, col);
			result_mark[tmp_infor.y][tmp_infor.x] = 1;
			stack[*top + 1].x = tmp_infor.x;
			stack[*top + 1].y = tmp_infor.y;
			result_top = creat_top(top);
			sum += move(maze, result_mark, row, col, stack, &result_top);
			count++;

			free_mark(result_mark, row);
		}
	}
	if (count == 0) {
		return 0;
	}
	else {
		return sum;
	}
}
