#include <stdio.h>
void main() {
	int a[6] = {57,5,6,13,4,60};
	int index1 = 0;
	int index2 = 0;
	for (int i = 0; i < 6; i++) {
		if (a[i] > a[i + 1]) {
			index1 = i;
			break;
		}	
	}
	for (int i = 6 - 1; i > index1 ; i--) {
		if (a[i] < a[i - 1]) {
			index2 = i;
			break;
		}
	}
	int temp;
	temp = a[index1];
	a[index1] = a[index2];
	a[index2] = temp;
	for (int i = 0; i < 6; i++) 
		printf("%d, ", a[i]);
	_getch();
}