#include <stdio.h>
void main() {
	int num = 20;
	int grate = 0, small = 0;
	int a[10] = { 20, 40, 30, -50, 70,-100, 35, 36, -39, 90};
	for (int i = 0; i < 10; i++) {
		if (a[i] > num)
			grate++;
		else if (a[i] < num)
			small++;
	}
	printf("%d grater than %d and %d less", grate, num, small);
	_getch();
}