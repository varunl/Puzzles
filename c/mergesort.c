#include <stdio.h>
#include <stdlib.h>

void display(int *list, int size);
void MergeSort(int *list, int low, int high);
void Merge(int *list, int low, int mid, int high);


int main() {
	int n;
	scanf("%d", &n);
	int *list;
	list = (int *) malloc (sizeof(int) * n);
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}

	printf("the list is: \n");
	display(list, n);

	// sort the list
	MergeSort(list, 0, n-1);

	printf("The sorted list is: \n");
	display(list, n);

}

void display(int *list, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d, ", list[i]);
	}
  printf("\n");
}

void MergeSort(int *list, int low, int high) {
	if (low == high) {
		return;
	}
	int mid = (low + high) / 2;
	
	MergeSort(list, low, mid);
	MergeSort(list, mid + 1, high);
	Merge(list, low, mid, high);
}

void Merge(int *list, int low, int mid, int high) {
	int *temp;
	temp = (int *) malloc(sizeof(int) * (high - low + 1));
	int i, index1, index2;
	i = 0, index1 = low, index2 = mid + 1;
	while(index1 <= mid && index2 <= high) {
		if (list[index1] < list[index2]) {
			temp[i] = list[index1];
			index1++;
		} else {
			temp[i] = list[index2];
			index2++;
		}
		i++;
	}

	while (index1 <= mid) {
		temp[i] = list[index1];
		index1++;
		i++;
	}

	while (index2 <= high) {
		temp[i] = list[index2];
		index2++;
		i++;
	}

	// merging to the original list

	int index;
	i = 0;
	for (index = low; index <= high; index++) {
		list[index] = temp[i];
		i++;
	}
}
