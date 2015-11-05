#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int* multiples1(int[], int);
void main() {
	int length = 0, result[10] = { 0 }, index;
	printf("Enter the length of the array: \n");
	scanf("%d", &length);
	int array[6];
	for (index = 0; index < length; index++)
		scanf("%d", &array[index]);
	*result = multiples1(array, length);
	for (index = 0; index < length; index++)
		printf("%d, ", result[index]);
	_getch();
}

int* multiples1(int array[10], int length) {
	int product = 1, result[10];
		for (int i = 0; i < length; i++) {
			if (array[i] == 0) {
				product *= array[i];
			}
			product *= array[i];
		}
	for (int i = 0; i < length; i++)
		result[i] = product / array[i];
	return *array;
}
