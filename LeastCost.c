#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void maxoccurence(int*, int);
int largest(int[], int);
void main() {
	int *number;
	int n;
	printf("Enter number of elemnts");
	scanf("%d", &n);
	number = (unsigned int*)malloc(sizeof(unsigned int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &number[i]);
	 maxoccurence(number, n);
	 _getch();
}

void maxoccurence(int* number, int n) {
	int numCount[10] = { 0 };
	for (int i = 0; i < n; i++)
		numCount[i++];
	int max = largest(numCount, n);
}

int largest(int numCount[10], int n) {
	int k;
	int large = numCount[0];
	int maxIndex = 0;
	for (int i = 1; i < n; i++) {
		if (numCount[i] >= large) {
			maxIndex++;
			large = numCount[i];
		}
	}
	printf("Enter K");
	scanf("%d", &k);
	if (k >= numCount[maxIndex])
		printf("%d", maxIndex);
	else
	    return maxIndex;
}