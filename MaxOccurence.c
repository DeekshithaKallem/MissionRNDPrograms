#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int maxoccurence(char*, int);
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
	string[index] = '\0';
	int result = maxoccurence(string, len);
	printf("the maximum occurence is %d", result);
	_getch();
}
int maxoccurence(char* string, int len)  {
	int alphabetscount[26] = {0};
	int maxindex;
	for (int i = 0; i < len; i++) {
		if (string[i] >= 'a' && string[i] <= 'z')
		    alphabetscount[string[i] - 97]++;
	}
	int max = alphabetscount[0];
	for (int i = 0; i < 26; i++) {
		if (alphabetscount[i] >= max) {
			max = alphabetscount[i];
			maxindex = i;
		}
	}
	printf(" \n the alphabet %c ", maxindex + 97);
	return max;
}