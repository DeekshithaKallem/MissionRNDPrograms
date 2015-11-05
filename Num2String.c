#include <stdio.h>
int main(){
	int num;
	printf("Enter a number\n");
	scanf("%d", &num);
	int temp = num;
	int count = 0;
	while (temp != 0){
		temp /= 10;
		count++;
	}
	printf("count is %d\n", count);
	char *given_string = (int*)malloc(sizeof(int)* count);
	int i = count - 1;
	int rem = 0;
	//given_string[0] = (char)6;
	while (num > 0)
	{
		rem = num % 10;
		num /= 10;
		given_string[i--] = rem + '0';
	}
	printf("at 0 %c\n", given_string[0]);
	given_string[count] = '\0';
	printf("string is %s\n", given_string);
	_getch();
	return 0;
}