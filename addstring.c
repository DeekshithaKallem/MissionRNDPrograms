#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void main() {
	char* nums,ch;
	char* num2;
	int len,len1 = 0,len2 = 0, i = 0,j, flag = 0;
	int index = 0;
	printf("enter length:\n");
	scanf("%d", &len);
	nums = (char*)malloc(sizeof(char)*len);
	num2 = (char*)malloc(sizeof(char)*len);
	printf("enter two numbers in num1,num2 format to add them:\n");
	for (i = 0; i < len ; i++)
		scanf(" %c", &nums[i]);
	nums[i] = '\0';
	for (i = 0, j = 0; i < len; i++) {
		if (nums[i] == ',') {
			flag = 1;
			len1 = i;
			nums[i] = '\0';
		}
		if (flag == 1) {
			index = i + 1;
			num2[j++] = nums[index];
		}
	}
	len2 = j;
	num2[j] = '\0';
	for (i = 0; nums[i] != '\0'; i++) 
		printf("%c + %c", nums[i], num2[i]);
	_getch();
}