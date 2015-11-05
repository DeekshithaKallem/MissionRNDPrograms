//Min Rank of a given number: Given an unsigned number as input, find the index of the number (index starts from 0) in all permutations of the number, sorted in ascending order. input 213: output 2 (as 123, 132, 213, 231, 312, 321 are the permutations and 2 is the index values of 213)
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdbool.h>
int MinimumRank(int);
int permutation(int*, int, int, int);
int NumberOccurences(int*, int, int);
int IndividualDigits(int);
bool IsEqual(int*, int);
bool IsAscending(int*, int);
int factorial(int);
void main() {
	int number;
	printf("Enter the number to find its min rank: ");
	scanf("%d", &number);
	printf("The rank of %d is %d\n", number, MinimumRank(number));
	_getch();
}

int MinimumRank(int number) {
	// counting number of digits in the given number
	int index,sum= 0, Digits_Count = IndividualDigits(number);
	int* digits;
	// allocating memory as per the digit count 
	digits = (int*)malloc(sizeof(int) * Digits_Count);
	int temp = number;
	// finding indiviual digit and placing it in reverse in an array
	for (index = Digits_Count - 1; index >= 0; index--) {
		digits[index] = number % 10;
		number /= 10;
	}
	// if the numbers are equal or are in ascending order then the rank is zero
	if (IsEqual(digits, Digits_Count) || IsAscending(digits, Digits_Count)) 
		return 0;
	// finding the permutation
	else  {
		for (int i = 0; i < Digits_Count; i++) 
			sum += permutation(digits, digits[0], i, Digits_Count);
		return sum;
	}
}

// count of indiviual digits
int IndividualDigits(int number) {
	int Digits_Count = 0;
	while (number > 0) {
		number /= 10;
		Digits_Count++;
	}
	return Digits_Count;
}

//function to check whether all the digits in the given number are equal or not
bool IsEqual(int *digits, int Digits_Count) {
	int number = digits[0];
	for (int i = 1; i < Digits_Count; i++) {
		if (number == digits[i])
			continue;
		return false;
	}
	printf("all the numbers are equal\n");
	return true;
}

//function to check whether all the digits are in ascending order or not
bool IsAscending(int *digits, int Digits_Count) {
	for (int i = 1; i < Digits_Count; i++) {
		if (digits[i - 1] <= digits[i])
			continue;
		return false;
	}
	printf("the numbers are in ascending order\n");
	return true;
}

// function to find the rank of the given number in all the permutations
int permutation(int *digits, int currentNum, int position, int Digits_Count) {
	int index, smallNumsCount = 0;
	// counting the number of digits less then the current number
	for (index = position + 1; index < Digits_Count; index++) {
		if (currentNum > digits[index])
			smallNumsCount++;
	}
	if (smallNumsCount == 0)
		return 0;
	else
		// number of occurences function for the duplicates 
		return (smallNumsCount * factorial(Digits_Count - position - 1)) / NumberOccurences(digits, position, Digits_Count);
}

int NumberOccurences(int* digits, int position, int Digits_Count) {
	int index, NumberOccurences[10] = { 0 }, product = 1;
	// number of occerences of each digits
	for (index = position; index < Digits_Count; index++) {
		NumberOccurences[digits[index]]++;
	}
	// factorial of each digit occurences
	for (index = 0; index < 10; index++) {
		if (NumberOccurences[index] > 1)
			product *= factorial(NumberOccurences[index]);
	}
	return product;
}

// factorial function using recursion
int factorial(int number) {
	if (number == 0 || number == 1)
		return 1;
	else
		return (number * factorial(number - 1));
}