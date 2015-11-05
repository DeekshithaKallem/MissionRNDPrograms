#include<stdio.h>
void delete_duplicates(int[], int);
void shift_elements(int[], int, int);
int main() {
	int no_of_elements1;
	printf("Enter  size of array\n");
	scanf("%d", &no_of_elements1);
	int *given_array = (int*)malloc(sizeof(int)* no_of_elements1);
	printf("Enter elements\n");
	for(int i = 0; i < no_of_elements1; i++)
		scanf("%d", &given_array[i]);
	delete_duplicates(given_array, no_of_elements1);
	return 0;
}
void delete_duplicates(int given_array[], int no_of_elements){
	for(int i = 0; i < no_of_elements; i++){
		for(int j = i + 1; j < no_of_elements; j++){
			if(given_array[i] == given_array[j]){
				shift_elements(given_array, no_of_elements, j);
				no_of_elements--;
			}
		}
	}
	for(int i = 0; i < no_of_elements; i++)
		printf("%d", given_array[i]);
	printf("\n");
	return;
}
void shift_elements(int given_array[], int no_of_elements, int index)
{
	while(index < no_of_elements){
		given_array[index] = given_array[index + 1];
		index++;
	}

	return;
}