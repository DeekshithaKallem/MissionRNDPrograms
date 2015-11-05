#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <conio.h>
void main() {
	int i,len = 0;
	int temp = 0;
	printf("enter len:");
	scanf("%d", &len);
	int* a;
	int CurrentSum = 0;
	int MaxSum = 0;
	a = (int*)malloc(sizeof(int) * len);
	printf("enter numbers:");
	for ( i = 0; i < len; i++)
		scanf("%d", &a[i]);
	CurrentSum = a[0] + a[1] + a[2];
	for (int i = 0; i < len; i++) {
		MaxSum = a[i] + a[i + 1] + a[i + 2];
	    if (MaxSum > CurrentSum) {
		    CurrentSum = MaxSum;
		}
	}
	/*for (int i = 0; i < len; i++) {
		int min = i;
		for (int j = i + 1; j < len; j++) {
			if (a[min] > a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < len; i++)
		printf("%d,  ", a[i]);*/
	printf("Maximum triplet: %d", CurrentSum);
	_getch();
}