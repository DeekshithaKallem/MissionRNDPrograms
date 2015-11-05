#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
void swap(char*, char*); 
void permut(char*, int, int);
int length(char *);
void main()
{
	char* number;
	number = (char*)malloc(sizeof(char*) * 8);
	printf("Enter a 8 digit number");
	scanf("%s", number);
	int len = length(number);
	permut(number, 0, len - 1);
	_getch();
}
void swap(char *digit1, char *digit2)
{
	char temp;
	temp = *digit1;
	*digit1 = *digit2;
	*digit2 = temp;
}

void permut(char *number, int startIndex, int endIndex)
{
	int index;
	if (startIndex == endIndex)
		printf("%s\n", number);
	else
	{
		for (index = startIndex; index <= endIndex; index++)
		{
			swap((number + startIndex), (number + index));
			permut(number, startIndex + 1, endIndex);
			swap((number + startIndex), (number + index));
		}
	}
}

int length(char * str) {
	int i;
	for (i = 0; str[i] != '\0'; i++);
	return i;
}