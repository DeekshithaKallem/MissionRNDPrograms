#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <conio.h>
//char* firstword(char*);
void main() {
	char* str = "hi i am sam";
	//char* str, ch;
	///int str_len = 100;
	//str = (char*)malloc(sizeof(char)*str_len);
	//for (int i = 0; (ch = getchar()) != '\n'; i++){
	//	str[i] = ch;
	//}
	//str[str_len] = '\0';
	for (int i = 0; str[i] != ' '; i++) 
	    printf("%c", str[i]);
}
/*char* firstword(char* str) {
	int i;
	for (i = 0; str[i] != ' '; i++) {
	}
	str[i] = '\0';
	return str;
}*/
