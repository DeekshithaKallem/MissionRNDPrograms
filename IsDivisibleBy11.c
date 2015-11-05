#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool IsDivisible1(char *);
bool IsDivisible2(char [], int);
void Testcases(char *, int);
bool IsEqual(char*);
bool IsNum(char*);
void main() {
	char* number, digit;
	int index, index1;
	printf("Enter the number to find if it is divisible by 11 or not: ");
	number = (char*)malloc(sizeof(char) * 10000);
	while ((digit = getchar()) == '0');
	if (digit != '\n') {
		number[0] = digit;
		for (index = 1; (digit = getchar()) != '\n'; index++)
			number[index] = digit;
		number[index] = '\0';
		if (IsNum(number))
			Testcases(number, index);
		else
			printf("Its not a valid number");
	}
	else
		printf("0 is divisible by 11");
	_getch();
}

void Testcases(char* number, int length) {
	if (length < 2)
		printf("%s is not divisible by 11", number);
	else if (IsEqual(number)) {
		if (length % 2 == 0)
			printf("%s is divisible by 11", number);
		else
			printf("%s is not divisible by 11", number);
	}
	else {
		if (IsDivisible1(number))
			printf("%s is divisible by 11", number);
		else
			printf("%s is not divisible by 11", number);
	}
}

bool IsEqual(char* number) {
	for (int index = 1; number[index]; index++) {
		if (number[0] != number[index])
		     return false;
	}
	return true;
}

bool IsNum(char* number) {
	for (int index = 0; number[index]; index++) {
		if (number[index] >= '0' && number[index] <= '9')
			continue;
		return false;
	}
	return true;
}
bool IsDivisible1(char* number) {
	int index, result = 0;
	for (index = 0; number[index] != '\0'; index++) {
		if (index % 2 == 0)
			result += number[index] - '0';
	    else
			result -= number[index] - '0';
	}

	if (result == 0 || result % 11 == 0)
		return true;
	return false;
}
/*bool IsDivisible2(char number[], int len) {
	int index;
	for (index = len - 1; (index - 2) >= 0; index--) {
		if (number[index - 1]  >= number[index]) {
			number[index - 1] = number[index - 1] - number[index];
			printf("\n1%c\n", number[index - 1]);
		}
		else if (number[index - 1] < number[index]) {
			printf("\n2%c\n", (number[index - 1] - 48));
			number[index - 1] = (number[index - 1] - '0') + 10 - (number[index] - '0');
			printf("\n3%c\n", (number[index - 1] - '0') );
			number[index - 2] -= '1';
		}
		
		number[index] = '\0';
	}
	if (number[0] == 0)
		return true;
	return false;
}*/

