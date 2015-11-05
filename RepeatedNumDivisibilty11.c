#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include <stdbool.h>
int digtsAreEqual(char *);
bool IsDivisible1(char *);
void Testcases(char *, int, int);
bool IsEqual(char*);
bool IsNum(char*);
int isValidInput(char *);
void formQ(char* , char* );
int length(char*);


void main() {
	char * P = (char *)malloc(sizeof(char) * 100);
	int index = 0;
	char digit;
	printf("Enter the P: \n");
	while ((digit = getchar()) == '0');

	if (digit != '\n') {
		P[index++] = digit;
		while ((digit = getchar()) != '\n') {
			P[index] = digit;
			index++;
		}
		P[index] = '\0';
		if (isValidInput(P)) {
			int K;
			printf("Enter K: ");
			scanf("%d", &K);
			//char * Q = (char *)malloc(sizeof(char) * 10000); i cant get the output wen malloc is used ?
			char Q[10000] = "";
			while (K > 0) {
				formQ(Q, P);
				K--;
			}
			Q[length(Q)] = '\0';
			printf("%s", Q);
			Testcases(P, index, K);
		}
		else
			printf("The given number is not a valid number .\n");
	}

	else
		printf("0 is not divisible by 11.\n");
	_getch();
}


void formQ(char * Q, char * P) {
		int i, j;
		i = length(Q);
		for (j = 0; P[j] != '\0'; i++, j++) {
			Q[i] = P[j];
		}
	}


int length(char* str) {
     int i;
	for (i = 0; str[i] != '\0'; i++);
	return i;
}


int isValidInput(char * number) {
	for (int index = 0; number[index] != '\0'; index++) {
		if (!(number[index] >= '0' && number[index] <= '9'))
			return 0;
	}
	return 1;
}

void Testcases(char* number, int length, int K) {
	if (length < 2)
		printf(" is not divisible by 11", number);
	else if (IsEqual(number)) {
		if ((K * length) % 2 == 0)
			printf(" is divisible by 11", number);
		else
			printf(" is not divisible by 11", number);
	}
	else {
		if (IsDivisible1(number))
			printf(" is divisible by 11", number);
		else
			printf(" is not divisible by 11", number);
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