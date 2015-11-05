// Given three unsigned numbers as input X, Y, Z find out X to the power of Y modulo Z (power(x,y) mod z)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
unsigned int XpowYmodZ(unsigned int, unsigned int, unsigned int);
void main() {
	unsigned int x,  y, z;
	printf("Enter x, y, z to find power(x, y)modz:\n ");
	scanf("%d %d %d", &x, &y, &z);
	printf("(%d ^ %d) mod %d) = %d\n", x, y, z, XpowYmodZ(x, y, z));
	_getch();
}

unsigned int XpowYmodZ(unsigned int x, unsigned int y, unsigned int z) {
	unsigned int res = 1;
	while (y > 0)
	{
		// if the power is even
		while (y % 2 == 0)
		{
			// formula
			x = ((x%z)*(x%z)) % z;
			y /= 2;
		}
		// if power is odd
		res = (res*x) % z;
		y--;
	}
	return res;
}