#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
void concat(char*, char*,int);
int length(char*);
void main() {
	char* string1, ch;
	char* string2;
	int index = 0;	string1 = (char*)malloc(sizeof(char)*20);
	string2 = (char*)malloc(sizeof(char)*20);
	printf("string 1:");
    gets(string1);
	printf("string 2:");
	gets(string2);
		if (string2 != '\0') {
			printf("enter the index to enter:");
			scanf("%d", &index);
			if (index >= 0) {
			    if (index < length(string2))
					concat(string1, string2, index);
				else
					printf("index out of range");
			}
			else
				printf("the index is not valid");
		}
	_getch();
}

void concat(char* string1, char* string2, int index1) {
	int index2 = 0, index;
	int len1 = length(string1);
	int len2 = length(string2);
	int temp = index1;
	for (index = (len1 + index1); index < (len1 + len2); index++) {
		string2[index] = string2[index1++];
	}
	string2[index] = '\0';
	for (index = temp; string1[index2] != '\0'; index++) 
		string2[index] = string1[index2++];
    printf("%s", string2);
}
int length(char* string) {
	int index;
	for ( index = 0; string[index] != '\0'; index++);
	return index;
}