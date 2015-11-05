// sum of digits where the input can be of any length(using strings)
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int SumOfDigits(int);
void main() {
	char* num, ch;
	int i,j = 0,res1 = 0;
	printf("enter a  num:");
	//allocating memory dynamically and  reading a number as string
	num = (char*)malloc(sizeof(int)*2000);
	for (i = 0; (ch = getchar()) != '\n'; i++)
		num[i] = ch;
	num[i] = '\0';
	//converting char array to integer
	while (num[j] != '\0') { 
		res1 = res1 * 10 + (num[j] - '0');
		j++;
	}
	//calling the function to add the digits in the number
	 int res = SumOfDigits(res1);
	 printf("%d", res);
	 _getch();
}

int SumOfDigits(int num) {
	int remainder, sum = 0;
	//adding indiviual digit to the sum and returning it
	while (num > 0) {
		remainder = num % 10;
		num = num / 10;
		sum += remainder;
	}
	return sum;
}
	
	