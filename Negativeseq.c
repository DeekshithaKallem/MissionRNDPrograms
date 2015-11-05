#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
void main() {
	int num[10], len, index, count = 0, greater = 0, resultindex = 0;
	printf("enter the lenth");
	scanf("%d", &len);
	printf("enter the numbers into array");
	for (index = 0; index < len; index++)
		scanf("%d", &num[index]);
	for (index = 0; index < len; index++) {
		if (num[index] < 0)
			count++;
		else
			count = 0;
		if (count > greater) {
			greater = count;
			resultindex = index;
		}
	}
	for (index = len - greater; index <= resultindex; index++) {
		printf("%d", num[index]);
    }
	_getch();
}
