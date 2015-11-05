// C Program to shuffle a given array
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<stdbool.h>
void randomize(int * arr, int n);
void swap(int *a, int *b);
//void printArray (int * arr, int n);

int MinimumRank(int *);
int permutation(int*, int, int, int);
int NumberOccurences(int*, int, int);
int IndividualDigits(int);
bool IsEqual(int*, int);
bool IsAscending(int*, int);
int factorial(int);


int main() {
	unsigned int number;
	printf("Enter the number:\n");
	scanf("%d", &number);
	int temp = number, i = 7;
	int digits[8] = { 0 }, remainder;
	// finding indiviual digit and placing it in reverse in an array
	while (temp > 0) {
		remainder = temp % 10;
		temp /= 10;
		digits[i] = remainder;
		i--;
	}

	//descending order ...to find last index of the resultantant array.
	int a;
	for (int k = 0; k < 8; k++) {
		for (int j = k + 1; j < 8; j++) {
			if (digits[k] < digits[j]) {
				a = digits[k];
				digits[k] = digits[j];
				digits[j] = a;
			}
		}
	}


	int resLength = MinimumRank(digits);
	//int * resultArray = (int *)malloc(sizeof(int) * resLength);
	unsigned int resultArray[40320] = { 0 };

	int len = 8;
	int index = 0;
	int count = 0;
	for (int i = 0; count <= resLength; i++) {
		randomize(digits, len);
		index = MinimumRank(digits);
		//changing array to number.
		unsigned int num = 0;
		for (int j = 0; j < 8; j++) {
			num = (num * 10) + digits[j];
		}
		if (resultArray[index] == 0) {
			resultArray[index] = num;
			count++;
			printf("%d\n", count);
		}
	}
	for (int resIndex = 0; resIndex < resLength; resIndex++) {
		printf("hello");
		printf("%d", resultArray[resIndex]);
		printf("\n");
	}
	
	return 0;
}



// A utility function to swap to integers
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}





// A function to generate a random permutation of arr[]
void randomize(int * arr, int n) {
	// Use a different seed value so that we don't get same
	// result each time we run this program
	srand(time(NULL));

	// Start from the last element and swap one by one. We don't
	// need to run for the first element that's why i > 0
	for (int i = n - 1; i > 0; i--) {
		// Pick a random index from 0 to i
		int j = rand() % (i + 1);
		// Swap arr[i] with the element at random index
		swap(&arr[i], &arr[j]);
	}
}




int MinimumRank(int* digits) {
	// counting number of digits in the given number
	int sum = 0;

	// if the numbers are equal or are in ascending order then the rank is zero
	if (IsEqual(digits, 8) || IsAscending(digits, 8))
		return 0;
	// finding the permutation
	else  {
		for (int i = 0; i < 8; i++)
			sum += permutation(digits, digits[0], i, 8);
		return sum;
	}
}


/*
// count of indiviual digits
int IndividualDigits(int number) {
int Digits_Count = 0;
while (number > 0) {
number /= 10;
Digits_Count++;
}
return Digits_Count;
}*/

//function to check whether all the digits in the given number are equal or not
bool IsEqual(int * digits, int Digits_Count) {
	for (int i = 1; i < Digits_Count; i++) {
		if (digits[0] == digits[i])
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