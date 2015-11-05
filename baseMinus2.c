#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING

#include<stdio.h>

void baseMin2(int decimalNumber);
int length(char * str);
void main() {
	int decimalNumber;
	printf("Entet the decimal number: \n");
	scanf("%d", &decimalNumber);
	baseMin2(decimalNumber);
	_getch();
}


void baseMin2(int decimalNumber) {
	char digits[100];
	int remainder;
	int index = 0;
	while (decimalNumber != 0) {
		remainder = decimalNumber % -2;
		decimalNumber /= -2;
		if (remainder < 0) {
			decimalNumber++;
			remainder += 2;
		}
		digits[index] = remainder + '0';
		index++;
	}
	digits[index] = '\0';
	int len = length(digits);
	for (index = 0; index < len / 2; index++) {
		digits[index] = digits[index] + digits[len - index - 1];
		digits[len - index - 1] = digits[index] - digits[len - index - 1];
		digits[index] = digits[index] - digits[len - index - 1];
		
	}
	printf("%s", digits);
}


int length(char * number) {
	int index;
	for (index = 0; number[index] != '\0'; index++);
	return index;
}