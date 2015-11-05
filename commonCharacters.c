//7. Given two strings, find out the common characters and print them.
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include<stdio.h>

void common(char * word1, char * word2, int size1, int size2);

void main() {
	char* string1, num, index;
	char* string2;
	int len1, len2;
	printf("enter the length of the string1:");
	scanf("%d", &len1);
	printf("enter string1:");
	string1 = (char*)malloc(sizeof(char) * len1);
	for (index = 0; index < len1; index++) {
		scanf(" %c", &string1[index]);
	}
	string1[index] = '\0';
	
	printf("enter the length of the string2:");
	scanf("%d", &len2);
	printf("enter string2:");
	string2 = (char*)malloc(sizeof(char) * len2);
	for (index = 0; index < len2; index++) {
		scanf(" %c", &string2[index]);
	}
	string2[index] = '\0';
	common(string1, string2, len1, len2);
	_getch();
}


void common(char * word1, char * word2, int size1, int size2) {
	//Taking two arrays as counts of alplhabets
	int arr_word1[26] = { 0 };
	int arr_word2[26] = { 0 };
	//Intialising size as greater of two Strings' Size
	int size = (size1 > size2) ? size1 : size2;
	for (int index = 0; index < size; index++) {
		//Incrementing count of corresponding alphabet in alphCountOfWord1 if present in String1
		if (word1[index] != '\0') {

			arr_word1[word1[index] - 97]++;
			arr_word1[word1[index] - 65]++;

		}
		//Incrementing count of corresponding alphabet in alphCountOfWord2 if present in String2
		if (word2[index] != '\0') {
			arr_word2[word2[index] - 97]++;
			arr_word2[word2[index] - 65]++;
		}

	}
	//printing the alphabets which are incremented in alphCountOfWord2 (common characters)
	for (int index = 0; index < 26; index++) {
		if (arr_word1[index] > 0 && arr_word2[index] > 0) {
			printf("%c ", index + 97);
		}
	}
}