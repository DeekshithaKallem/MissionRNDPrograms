//given a sorted array insert a given number into the array at appropriate position(we can even insert the element at the last and beginning)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void addNum(int *, int);
int binary_search(int*, int, int, int);
void main() {
	int a[6] = { 15, 20, 95, 110, 120 };
	int number;
	printf("Enter the number to be inserted: ");
	scanf("%d", &number);
	addNum(a, number);
	for (int i = 0; i < 6; i++)
		printf("%d\n", a[i]);
	_getch();
}

void addNum(int * a, int number) {
	int i;
	int temp;
	int size = 6;
	i = binary_search(a, 0, size - 1, number);
	if (i == size)
		a[i - 1] = number;
	while (i < size) {
		a[size - 1] = a[size - 2];
		size--;
	}
	a[i] = number;
}
int binary_search(int* a, int low, int high, int x) {
	int mid;
	while (low < high) {
		mid = (low + high) / 2;
		if (a[mid] == x)
			return mid;
		else if (a[mid] > x)
			high = mid - 1;
		else
			low = mid + 1;
	}
	if (a[low] == x)
		return low;
	else if (a[low] > x)
		return low;
	else
		return low + 1;
}