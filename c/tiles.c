// zio 2009, lay tiles on the floor	

#include <stdio.h>

void LayTiles(int len, int u, int l, int *count, int check);

int main() {
	int len;
	int u, l; // u = upper row of the floor, l = lower row of the floor
  printf("Enter the floor length. (Width is always 2): ");
	scanf("%d", &len);
	int count = 0; // counter for number of ways
	LayTiles(len, 0, 0, &count, 1);
	printf("The number of ways = %d\n", count);

}

void LayTiles(int len, int u, int l, int *count, int can_use) {
	if (u > len || l > len) {
		return;
	}

	if (u == len && l == len) {
		(*count)++;
		return;
	}

	if (u == l) {
		LayTiles(len, u + 1, l + 2, count, 1);
		LayTiles(len, u + 2, l + 1, count, 1);
		LayTiles(len, u + 1, l + 1, count, 1);
		if (can_use == 1) {
			LayTiles(len, u + 2, l + 2, count, 0);
		}
	} else if (u == l - 1) {
		LayTiles(len, u + 2, l + 1, count, 1);
		LayTiles(len, u +2, l, count, 1);
	} else if (u == l + 1) {
		LayTiles(len, u + 1, l + 2, count, 1);
		LayTiles(len, u, l + 2, count, 1);
	}
}
		
	


