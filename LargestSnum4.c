#include<stdio.h>
char* great(char *, char *);
int len(char *);
void SignOfNum(char *, char *);
char* check(char *, char *,int, int);
void main() {
	char *a = "-000111";
	char *b = "-000202";
	//checking the signs of numbers
	SignOfNum(a, b);
	_getch();
}
void SignOfNum(char * a, char * b) {
	if (a[0] == '-' && b[0] == '-') {
		//if both the numbers are negative 
		if (great(a, b) == a)
			printf("%s", b);
		else
			printf("%s", a);
	}
	//if one of them is negative
	else if (a[0] == '-')
		printf("%s", b);
	else if (b[0] == '-')
		printf("%s", a);
	//if both are positive
	else
		printf("%s", great(a, b));


}
char* great(char * a, char * b) {
	char *great = "";
	int len1 = len(a);
	int len2 = len(b);
	int i1 = 0;
	int i2 = 0;
	//getting the index of the actual number(00001 then we will get as 1)
	while (i1 < len1) {
		if (a[i1] != '0' && a[i1] != '-')
			break;
		i1++;
	}

	while (i2 < len2){
		if (b[i2] != '0')
			break;
		i2++;
	}
	great = check(a, b, i1, i2);
	return great;
}
//length of string
int len(char * a) {
	int i;
	for (i = 0; a[i] != '\0'; i++);
	return i;
}

char* check(char * a, char * b, int i1, int i2) {
	int len1 = len(a);
	int len2 = len(b);
	//getting the actual number without zeros at the beginning
	int actNumLen1 = len1 - i1;
	int actNumLen2 = len2 - i2;
	//conditions
	if (actNumLen1 < actNumLen2)
		return b;
	else if (actNumLen1 > actNumLen2)
		return b;
	else if (actNumLen1 == actNumLen2) {
		for (; i1 < len1 && i2 < len2; i1++, i2++) {
			if (a[i1] == b[i2])
				continue;
			else if (a[i1] < b[i2]) {
				return b;
			}
			else {
				return a;
			}

		}
	}
	return a;
}