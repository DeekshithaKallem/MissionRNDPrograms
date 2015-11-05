#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int Conditions(int, int);
int Product(int, int);
int add(int, int);
void main() {
	int X, Y, product;
	printf("Enter number 1 and number 2 to multiply using Bit operations:\n ");
	scanf("%d %d", &X, &Y);
	printf("Product of %d and %d is %d", X, Y, Conditions(X, Y));
	_getch();
}

int Conditions(int X, int Y) {
	//checking if any one of the number is zero
	if (X == 0 || Y == 0)
		return 0;
	// checking if any number is 1
	else if (X == 1)
		return Y;
	else if (X == 1)
		return Y;
	// checking if the number is negative
	else if (X < 0) {
		X = ~X - (-1); // -10 -> ~(-10) = 9 + 1 = 10
		return (~Product(X, Y) -(-1)); //20 -> ~(20) = -21 + 1 = -20  
	}
	else
		// otherwise normal multiplication
		return Product(X, Y);
}

// using russian multiplication
int Product(int X, int Y) {
	int result = 0;
	 
	while (X > 0)
	{
		// adding to the anwer if first number is odd
		result = ((X & 1) > 0) ? (result - (~Y) - 1) : result;
		// multiplying the number x by 2  everytime
		X >>= 1;
		// dividing the number x by 2  everytime
		Y <<= 1;	
	}
	return result;
}

// binary adder using bitwise (another solution) but not required as (result - (~Y) - 1) will add the result with the number
int add(int result, int Y) {
	int carry;
	while(Y != 0) {
		carry = result & Y;
		//printf("%d carry", carry);
		result = result ^ Y;
		//printf("%d result", result);
		Y = carry << 1;
		//printf("%d num2", number2);
	}
	return result;
}
