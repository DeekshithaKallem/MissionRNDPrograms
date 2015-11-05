#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void testCases(char*);
bool ifAllZeros(char*);
void reverse(char*);
int length(char*);


void main() {
	char * binaryNumber = (char *)malloc(sizeof(char) * 10000);
	int index = 0;
	char digit;

	//storing binary number
	printf("Enter the binary number: \n");

	while ((digit = getchar()) != '\n') {
		//checking the string entering consists only digits 0 or 1

		if ((digit == '0') || (digit == '1')) {
			binaryNumber[index] = digit;
			index++;
		}
		else {
			printf("The given number is not a valid binary number .\n");
			_getch();
		}
	}

	binaryNumber[index] = '\0';
	testCases(binaryNumber);
	_getch();
	return 0;
}

void testCases(char * binaryNumber) {
	int binaryLength = length(binaryNumber);
	char octalNumber[1000] = "";
	if (ifAllZeros(binaryNumber))
		octalNumber[0] = '0';

	else {
		int octalIndex = 0;
		int binaryIndex = binaryLength - 1;

		while (binaryIndex - 2 >= 0){
			octalNumber[octalIndex] = (((binaryNumber[binaryIndex - 2] - 48) * 4) + ((binaryNumber[binaryIndex - 1] - 48) * 2) + binaryNumber[binaryIndex] - 48) + 48;
			binaryIndex = binaryIndex - 3;
			octalIndex++;
		}

		if (binaryIndex == 1)
			octalNumber[octalIndex] = (((binaryNumber[binaryIndex - 1] - 48) * 2) + binaryNumber[binaryIndex] - 48) + 48;
		else if (binaryIndex == 0)
			octalNumber[octalIndex] = binaryNumber[binaryIndex];
		reverse(octalNumber);
		printf("\nOctal Number is :%s", octalNumber);
	}
}

bool ifAllZeros(char * binary) {
	for (int index = 0; binary[index] != '\0'; index++) {
		if (binary[index] == '0')
			continue;
		return false;
	}
	return true;
}


void reverse(char  * octalNumber) {
	// reversing the answer (swap)
	int len = length(octalNumber);
	for (int index = 0; index < len / 2; index++) {
		int temp;
		octalNumber[index] = octalNumber[index] + octalNumber[len - index - 1];
		octalNumber[len - index - 1] = octalNumber[index] - octalNumber[len - index - 1];
		octalNumber[index] = octalNumber[index] - octalNumber[len - index - 1];
	}
}



int length(char * str) {
	int index;
	for (index = 0; str[index] != '\0'; index++);
	return index;
}


