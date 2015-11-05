#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int minimalsum(int*);
void main() {
	int* UnsortedArray, num, index;
	int len = 5;
	printf("enter the elements in array:");
	UnsortedArray = (int*)malloc(sizeof(int) * len);
	for (index = 0; index < len; index++) {
		scanf("%d", &UnsortedArray[index]);
	}
	int minimum = minimalsum(UnsortedArray);
	printf("the smallest is %d", minimum);
	_getch();
}
int minimalsum(int * UnsortedArray) {
	int minimal1 = ((UnsortedArray[0] > UnsortedArray[1]) ? UnsortedArray[0] : UnsortedArray[1]);
	int minimal2 = ((UnsortedArray[0] < UnsortedArray[1]) ? UnsortedArray[0] : UnsortedArray[1]);
	for (int index = 2; index < 5; index++){
		if (minimal2 > UnsortedArray[index]) {
			minimal1 = minimal2;
			minimal2 = UnsortedArray[index];
		}
		else if (minimal1 > UnsortedArray[index] && minimal2 != UnsortedArray[index]) {
			minimal1 = UnsortedArray[index];
		}
	}
	return (minimal1 + minimal2);
}
	
		