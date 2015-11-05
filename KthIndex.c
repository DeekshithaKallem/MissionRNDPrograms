#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void kthindex(char*, int);
void main() {
	char* str;
	int k;
	str = (char*)malloc(sizeof(char)* 10);
	printf("Enter the string");
	scanf("%s", str);
	printf("enter the index:");
	scanf("%d", &k);
	if (k > 0)
	   kthindex(str, k);
	_getch();
}

void kthindex(char* str, int k) {
	int index;
	for (index = 0; str[index + k] != '\0'; index++);
	printf("%c", str[index]);
}