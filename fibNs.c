// program to convert the given number to fibonacci number
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void fibonacci(int);
void ones(int);
void main() {
	printf("Enter number");
	int number;
	scanf("%d", &number);
	fibonacci(number);
	_getch();
}

void fibonacci(int number) {
	int first = 1;
	int second = 1;
	int third;
	int sum = 2;
	int noOf1 = 2;
	while (sum < number) {
		third = first + second;
		first = second;
		second = third;
		sum += third;
		noOf1++;
	}
	int dup = sum;
	if (sum == number)
		ones(noOf1);
	else {
		int j = 1;
		while (dup > 0) {
			j++;
			dup = sum;
			printf("1");
		dup -= first;
		second = first;
		first = third - first;
		third = second;
		if (dup == number) {
			printf("0");
			ones(noOf1 - j);
			break;
		}
		
	}
	}
}
 
void ones(int noOf1) {
	while (noOf1) {
		printf("1");
		noOf1--;
	}
}