#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int winnerElement(unsigned int*, int);
void main() {
	unsigned int *arr, n;
	arr = (unsigned int*)malloc(sizeof(unsigned int) * 10);
	printf("Fill the array");
	for (int i = 0; i < 10; i++)
		scanf("%d", &arr[i]);
	printf("Enter no. of elemnts to be summed:");
	scanf("%d", &n);
	int res = winnerElement(arr, n);
	printf("%d", res);
	_getch();
}

int winnerElement(unsigned int* arr, int n) {
	int win = 0;
	int sum = 0;
	int winIndex;
	for (int i = n / 2; i < 10 - (n / 2); i++) {
		for (int j = 0, k = i + n / 2; j < i; j++, k--) {
			sum += arr[j] + arr[k];
			printf("\n%d\n", sum);
		}
		if (sum > win) {
			winIndex = i;
			win = sum;
		}
	}
	return arr[winIndex];
}