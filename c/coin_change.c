#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int *calculated_change;

int Min(int denominations[], int num_den, int amount) { int min = -1; 
	int i; 
	for (i = 0; i < num_den; i++) {
		int previous = amount - denominations[i];
		if (previous >= 0) {
			if (min = -1) {
				int temp;
				min = GetChange(previous, denominations, num_den);
			}
			if (min > calculated_change[previous]) {
				min = GetChange(previous, denominations, num_den);
			}
		}
	}
	return min;
}

int GetChangeIterative(int amount, int denominations[], int num_den) {
	int i;
	for (i = 1; i <= amount; i++) {
		calculated_change[i] = Min(denominations, num_den, i) + 1;
	}

	return calculated_change[amount];
}
		
	
int GetChange(int amount, int denominations[], int num_den) {
	if (calculated_change[amount] > 0) {
		return calculated_change[amount];
	}
	int change;
	change = Min(denominations, num_den, amount) + 1;
	calculated_change[amount] = change;
	return change;
}

void init(int n) {
	calculated_change = malloc(sizeof(int) * (n + 1));
	bzero(calculated_change, sizeof(int) * (n + 1));
}

int main() {
	int n;
	while (1) {
		scanf("%d", &n);
		if (n == -1) {
			break;
		}
		init(n);
		int denominations[] = {1, 5, 10, 51};
		int num = sizeof(denominations) / sizeof(int);
		int change;
		change = GetChangeIterative(n, denominations, num);
		printf("Number of coins required: %d\n", change);
		free(calculated_change);
	}
}

