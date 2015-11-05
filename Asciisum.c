#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int Asciisum(char*, int);
void main() {
	char* string, num, index;
	int len;
	printf("enter the legth odf the array:");
	scanf("%d", &len);
	printf("enter the elements in array:");
	string = (char*)malloc(sizeof(char) * len);
	for (index = 0; index < len; index++) {
		scanf(" %c", &string[index]);
	}
	int result = Asciisum(string, len);
	printf("%d", result);
	_getch();
}
int Asciisum(char* string, int len) {
	int sum = 0;
	for (int index = 0; index < len; index++) {
		sum += string[index];
	}
	return sum;
}

