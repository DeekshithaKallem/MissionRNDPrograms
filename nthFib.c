
#include <stdio.h>
int nthfibonacci(int);
int main(){
	int num;
	printf("Enter number\n");
	scanf("%d", &num);
	int fibonacci_number = nthfibonacci(num);
	printf("%d\n", fibonacci_number);
	_getch();
	return 0;
}
int nthfibonacci(int num){
	int first = 0;
	int second = 1;
	int i = 0;
	int third;
	for (i = 2; i < num; i++){
		third = first + second;
		first = second;
		second = third;
	}
	return third;
}