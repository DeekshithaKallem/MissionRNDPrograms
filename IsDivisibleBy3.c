#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
void formQ(char* Q, char* P);
void testCases(char * P, int length);
bool digtsAreEqual(char * P);
int sumOfDigits(char * P);
bool isValidInput(char * P);
int length(char* str);
void intToCharArr(int number);


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
			char Q[10000] = "";
			while (K > 0) {
				formQ(Q, P);
				K--;
			}
			Q[length(Q)] = '\0';
			printf("The number %s ", Q);
			testCases(P, index);
		}
		else
			printf("The given number is not a valid number .\n");
	}
	else
		printf("0 is divisible by 3.\n");
	_getch();
	return 0;
}


void formQ(char * Q, char * P) {
	int index1, index2, plength, qlength;
	plength = length(P);
	index1 = qlength = length(Q);
	for (index2 = 0; index1 < (plength + qlength); index1++, index2++)
		Q[index1] = P[index2];
}


int length(char* number) {
	int index;
	for (index = 0; number[index] != '\0'; index++);
	return index;
}


bool isValidInput(char * number) {
	for (int index = 0; number[index] != '\0'; index++) {
		if (!(number[index] >= '0' && number[index] <= '9'))
			return false;
	}
	return true;
}



void  testCases(char * number, int length) {
	int sum = 0;
	if (digtsAreEqual(number))
		sum = (number[0] - 48) * length;
	else
		sum = sumOfDigits(number);
	intToCharArr(sum);
}


bool digtsAreEqual(char * number) {
	for (int index = 1; number[index] != '\0'; index++) {
		if (number[0] == number[index])
			continue;
		return false;
	}
	return true;
}


int  sumOfDigits(char * number) {
	int sum = 0;

	for (int index = 0; number[index] != '\0'; index++)
		sum += number[index] - '0';
	return sum;
}

void intToCharArr(int number) {
	char  charSum[10] = "";
	int index = 0;
	while (number > 0) {
		charSum[index] = (number % 10) + 48;
		number /= 10;
		index++;
	}
	charSum[index] = '\0';

	// reversing the charSum
	int temp;
	int charSumLen = length(charSum);
	for (int i = 0; i < charSumLen / 2; i++) {
		charSum[i] = charSum[i] + charSum[charSumLen - i - 1];
		charSum[charSumLen - i - 1] = charSum[i] - charSum[charSumLen - i - 1];
		charSum[i] = charSum[i] - charSum[charSumLen - i - 1];
		
	}

	if (length(charSum) == 1) {
		if ((charSum[0] == '3') || (charSum[0] == '6') || (charSum[0] == '9')) {

			printf("is divisible by 3.\n");
		}
		else
			printf("is not divisible by 3.\n");
	}
	else
		intToCharArr(sumOfDigits(charSum));
}