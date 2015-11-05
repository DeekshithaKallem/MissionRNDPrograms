#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void add(char* , char* );
int isValidInput(char *);
void testCases(char*, char*);
int length(char*);

void main() {
	char * num1 = (char *)malloc(sizeof(char) * 10000);
	char *num2 = (char *)malloc(sizeof(char) * 10000);
	int index1 = 0;
	int index2 = 0;
	char digit;
	//storing number1
	printf("Enter the number1: \n");
	while ((digit = getchar()) == '0');
	num1[index1++] = digit;
	while ((digit = getchar()) != '\n') {
		num1[index1] = digit;
		index1++;
	}
	num1[index1] = '\0';
	//storing number2
	printf("Enter the number2: \n");
	while ((digit = getchar()) == '0');
	num2[index2++] = digit;
	while ((digit = getchar()) != '\n') {
		num2[index2] = digit;
		index2++;
	}
	num2[index2] = '\0';
	if (isValidInput(num1) && isValidInput(num2)) 
		testCases(num1, num2);
	_getch();
}


int isValidInput(char * number) {
	for (int index = 0; number[index] != '\0'; index++) {
		if (!(number[index] >= '0' && number[index] <= '9'))
			return 0;
	}
	return 1;
}
	void testCases(char * num1, char* num2) {
		if (num1 == NULL || num2 == NULL)
			printf("any of these numbers are null cannot be added");
		else if (num1 == "0")
			printf("\n 0 + %s = %s", num2, num2);
		else if (num2 == "0")
			printf("\n 0 + %s = %s", num1, num1);
		else
			add(num1, num2);
	}

	int length(char* number) {
		int i;
		for (i = 0; number[i] != '\0'; i++);
		return i;
	}

	// getting each digit from the last
	int getcharval(const char *number, int index) {
		int length = strlen(number);
		if (index < length)
			return number[length - index - 1] - 48;
		return 0;
	}

	void add(char* num1, char* num2) {
		char* answer;
		answer = (char *)malloc(sizeof(char) * 10000);
		int index, len1 = length(num1), len2 = length(num2), largestLength, sum, carry = 0;
		// finding the largest length of both the numbers
		largestLength = len1 > len2 ? len1 : len2;
		for (index = 0; index < largestLength; index++){
			char ch1 = getcharval(num1, index);
			char ch2 = getcharval(num2, index);
			// addition of the digits along with carry
			sum = ch1 + ch2 + carry;
			carry = 0;
			// carry is updated with the sum is greater than 9
			if (sum > 9){
				carry = 1;
				sum -= 10;
			}
			answer[index] = sum + 48;
		}
		// if the last digit sum is greater than 9 
		if (carry) answer[index++] = carry + 48;
			answer[index] = '\0';
			// reversing the answer (swap)
			for (index = 0; index < strlen(answer) / 2; index++) {
				answer[index] = answer[index] + answer[strlen(answer) - index - 1];
				answer[strlen(answer) - index - 1] = answer[index] - answer[strlen(answer) - index - 1];
				answer[index] = answer[index] - answer[strlen(answer) - index - 1];
			}
			printf("%s\n", answer);
		}