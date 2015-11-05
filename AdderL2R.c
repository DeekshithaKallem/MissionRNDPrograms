#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int length(char * str);

void main() {
	char* number1 = (char*)malloc(sizeof(char*) * 1000);
	char* number2 = (char*)malloc(sizeof(char*) * 1000);

	printf("Enter Number 1: \n");
	scanf("%s", number1);
	printf("Enter Number 2: \n");
	scanf("%s", number2);

	int length1 = length(number1);
	int length2 = length(number2);

	if (length1 != length2) {
		printf("The number are of different lengths!!");
		_getch();
		exit(0);
	}

	char result[9]; 
	result[0] = '0';
	int k = 0, i = 0;
	while (k < length(number1)) {
		result[k+1] = (number1[k] + number2[k]) - 48;
		if (result[k+1] < '9')
			i = k+1;
		else if (result[k+1] > '9') {
			result[k+1] = result[k+1] - 10;
			int j;
			for (j = k; j >= i; j--) {
				if (result[j] == '9') 
					result[j] = '0';
				else if (result[j] < '9') {
					result[j] = result[j] + 1;
					i = k + 1;
				}
			}
		}
		k++;
	}
	result[k+1] = '\0';
	printf("The Sum is %s", result);
	_getch();
}

int length(char * str) {
	int i;
	for (i = 0; str[i] != '\0'; i++);
	return i;
}



