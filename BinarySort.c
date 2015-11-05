#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int NoOfZeros1(int[]);
void main() {
	int array[100], i;
	printf("enter the 0's or 1's into array\n");
	for (i = 0; i < 100; i++)
		scanf("%d", &array[i]);
	int NoZeros = NoOfZeros1(array);
	for (i = 0; i < NoZeros; i++)
		printf("0");
	for (i = NoZeros; i < 10; i++)
		printf("1");
	_getch();
}

int NoOfZeros1(int array[10]) {
	int NoZeros = 0;
	printf("hi");
	for (int i = 0; i < 10; i++) {
		if (array[i] == 0)
			NoZeros++;
	}
	return NoZeros;
}