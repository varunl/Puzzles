// problem 1: electoral rolls FEB 2005

#include <stdio.h>
#include <stdlib.h>

void DisplayInput(int num_lists, int *list_size, int **lists);
int FindMin(int num_lists, int *list_size, int **current_index, int **lists);

int main() {
	int numLists;
	scanf("%d", &numLists);
	int sum = 0;
	
	int *list_size = (int *) malloc(sizeof(int) * numLists);
	int **lists = (int **) malloc(sizeof(int *) * numLists);

	int i;
	for (i = 0; i < numLists; i++) {
		scanf("%d", &list_size[i]);
		sum += list_size[i];
		lists[i] = (int *) malloc(sizeof(int) * list_size[i]);
		int j;
		for (j = 0; j < list_size[i]; j++) {
			scanf("%d", &lists[i][j]);
		}
	}
//	DisplayInput(numLists, list_size, lists);

	int *current_index = (int *) malloc(sizeof(int) * numLists);
	for (i = 0; i < numLists; i++) {
		current_index[i] = 0;
	}

	int num;
	for (i = 0; i < sum; i++) {
		num = FindMin(numLists, list_size, &current_index, lists);
		printf("%d\n", num);
	}
}

void DisplayInput(int num_lists, int *list_size, int **lists) {
	int i, j;
	for (i = 0; i < num_lists; i++) {
		printf("%d ", list_size[i]);
		for (j = 0; j < list_size[i]; j++) {
			printf("%d ", lists[i][j]);
		}
		printf("\n");
	}
}

int FindMin(int num_lists, int *list_size, int **current_index, int **lists) {
	int i, j;
	int min;
	int index;
	//min = lists[0][(*current_index)[0]];
	min = 100000000;
	int check = 1;
	for (i = 0; i < num_lists; i++) {
		if ((*current_index)[i] < list_size[i]) {
			if (check) {
				min = lists[i][(*current_index)[i]];
				check = 0;
			}
			if (lists[i][(*current_index)[i]] <= min) {
				min = lists[i][(*current_index)[i]];
				index = i;
			}
		}
	}
	(*current_index)[index]++;
	return min;
}
