#include <stdio.h>
#include <stdlib.h>
void exchange(int [], int);
int main(){
	int a[6];
	int n = 6;
	printf("Enter any six elements\n");
	for (int i = 0; i < 6; i++)
		scanf("%d", &a[i]);
	exchange(a, n);
	_getch();
	return 0;
}
void exchange(int a[6], int n){
	int temp1 = 0, temp2 = 0;
	int index1;
	int index2;
	int i;
	for (i = 0; i < n; i++){
		if (a[i] < a[i + 1]){
			continue;
		}
		else{
			temp1 = a[i];
			index1 = i;
		    break;
	    }	
	}
	for (i = n - 1; i > index1; i--){
		if (a[i] > a[i - 1])
			continue;
		else{
			temp2 = a[i];
			index2 = i;
			break;
		}
	}
	a[index1] = temp2;
	a[index2] = temp1;
	for (i = 0; i < n; i++)
		printf("%d\t", a[i]);
	return;
}