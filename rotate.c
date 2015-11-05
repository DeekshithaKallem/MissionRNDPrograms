#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void rotate(int*, int, int);
void main() {
	int* array;
	int len, index, rotationcount = 0;
	printf("Enter the length");
	scanf("%d", &len);
	array = (int*)malloc(sizeof(int)*len);
	for (index = 0; index < len; index++)
		scanf("%d", &array[index]);
	printf("enter the no. of rotations");
	scanf("%d", &rotationcount);
	if (rotationcount != len)
	     rotate(array, rotationcount, len);
	else {
		for (index = 0; index < len; index++)
			printf("%d", array[index]);
	}
	_getch();
}

/*void rotate(int* array, int rcount, int len) {
	int index, last;
	for (int i = 0; i < rcount; i++) {
		last = array[len - 1];
		for (index = len - 1; index > 0; index--) {
			array[index] = array[index - 1];
		}
		array[0] = last;
	}
	for (index = 0; index < len; index++)
		printf("%d", array[index]);
}*/
void rotate(int* array, int rcount, int len) {
	int index, temp;
	for (index = rcount - 1; index > 0; index--) {
		temp = array[index];
		array[index] = array[index - 1];
		array[index - 1] = temp;
	}
	for (index = len - 1; index > rcount; index--) {
		temp = array[index];
		array[index] = array[index - 1];
		array[index - 1] = temp;
	}
	for (index = 0; index < len; index++)
		printf("2%d\n", array[index]);
	for (index = 0; index < len; index++) {
		temp = array[index];
		array[index] = array[index + 1];
		array[index + 1] = temp;
	}
	for (index = 0; index < len; index++)
		printf("3%d\n", array[index]);
}