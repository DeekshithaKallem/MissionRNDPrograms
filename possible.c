#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int rank1(int);
int factorial(int, int);
void main() {
	int number;
	printf("Enter the number to find its rank");
	scanf("%d", &number);
	int rank = rank1(number);
	printf("rank is : %d", rank);
	_getch();
}

int rank1(int number) {
	int remainder = 0, count = 0, noOfDigits;
	int temp = number;
	int dup;
	for (noOfDigits = 0; temp > 0; noOfDigits++) {
		dup = temp;
		temp /= 10;
	}
	while (number > 0) {
		remainder = number % 10;
		if (remainder < dup)
			count++;
		number /= 10;
	}
	return factorial(count, noOfDigits);
}

int factorial(int count, int noOfDigits) {
	int fact = 1;
	for (int i = 1; i <= count; i++) {
			fact = count * (noOfDigits - 1);
	}
	return fact;
}
