#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int FindN(int*);
int Condition(int*, int);
void main() {
	int number[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 32, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	printf("%d", FindN(number));
	_getch();
}

int FindN(int* number) {
	int index = 1;
	index = Condition(number, index);
	while (number[index] <= number[index - 1]) {
		index = index / 2 + index / 4;
		if (number[index] < number[index + 1])
		   index = Condition(number, index);
	}
	return index;
}
int Condition(int* number, int index) {
	while (number[index] < number[index + 1])
		index *= 2;
	return index;
}


