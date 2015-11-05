#include<stdio.h>
int* remove_ele(int [], int, int, int);
int main(){
	int no_of_elements;
	printf("Enter no of elements\n");
	scanf("%d", &no_of_elements);
	int *given_array = (int*) malloc(sizeof(int)* no_of_elements);
	printf("Enter elements\n");
	for (int i = 0; i < no_of_elements; i++)
		scanf("%d", &given_array[i]);
	int m;
	int n;
	printf("Enter ith index\n");
	scanf("%d", &m);
	printf("Enter jth index\n");
	scanf("%d", &n);
	given_array = remove_ele(given_array, no_of_elements, m, n);
	int i = 0;
	while (given_array[i] != '\0')
	{
		printf("%d ", given_array[i++]);
	}
	_getch();
	return 0;
}
int* remove_ele(int given_array[], int no_of_elements, int i, int j){
	if (j + 1 == '\0')
		given_array[i] = '\0';
	else{
		printf("i is %d\n", i);
		while (j < no_of_elements){
			given_array[i] = given_array[++j];
			i++;
		}
		given_array[i - 1] = '\0';
	}
	return given_array;
}