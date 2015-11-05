#include <stdio.h>
void deci_to_hexa(int decimal_num);
int main(){
	int decimal_num;
	printf("Enter decimal number\n");
	scanf("%d", &decimal_num);
	deci_to_hexa(decimal_num);
	_getch();
	return 0;
}
void deci_to_hexa(int decimal_num){
	int rem = 0;
	int temp = decimal_num;
	char hexa[20];
	int i = 0;
	while (temp != 0){
		rem = temp % 16;
		if (rem < 10)
			rem = rem + 48;
		else
			rem = rem + 55;
		hexa[i++] = rem;
		temp /= 16;
	}
	int j;
	for (j = i - 1; j >= 0; j--){
		printf(" %c", hexa[j]);
	}
	return;
}