#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
int IsVowel(char*);
void main() {
	char* word, ch;
	int len, i, a;
	int NoOfLetters = 0;
	printf("enter the string:");
	word = (char*)malloc(sizeof(char)*50);
	for (i = 0; (ch = getchar()) != '\n'; i++) {
		
		word[i] = ch;
		if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z'))
			NoOfLetters++;
	}
	word[i] = '\0';
	a = IsVowel(word);
	printf("vowels: %d\nconsonants: %d", a, NoOfLetters - a);
	_getch();
}

int IsVowel(char* word) {
	int count = 0;
	for (int i = 0; word[i] != '\0'; i++) {
		if (word[i] == 'a' || word[i] == 'A' || word[i] == 'e' || word[i] == 'E' || word[i] == 'i' || word[i] == 'I' || word[i] == 'o' || word[i] == 'O' || word[i] == 'u' || word[i] == 'U')
			count++;
	}
	return count;
}