#include <stdio.h>
void combiningarrays(int[], int, int[], int);
void main(){
	int no_of_elements1, no_of_elements2;
	printf("Enter  size of array1\n");
	scanf("%d", &no_of_elements1);
	printf("Enter  size of array2\n");
	scanf("%d", &no_of_elements2);
	int *given_array1 = (int*)malloc(sizeof(int)* no_of_elements1);
	int *given_array2 = (int*)malloc(sizeof(int)* no_of_elements2);
	int *given_array3 = (int*)malloc(sizeof(int)* no_of_elements1 + no_of_elements2);
	printf("Enter elements in array1 in ascending order\n");
	for (int i = 0; i < no_of_elements1; i++){
		scanf("%d", &given_array1[i]);
	}
	printf("Enter elements in array2 in descending order\n");
	for (int i = 0; i < no_of_elements2; i++){
		scanf("%d", &given_array2[i]);
	}
	combiningarrays(given_array1, no_of_elements1, given_array2, no_of_elements2, given_array3);
	for (int i = 0; i < no_of_elements1 + no_of_elements2; i++){
		printf("%d ", given_array3[i]);
	}
	_getch();
}
void combiningarrays(int given_array1[], int no_of_elements1, int given_array2[], int no_of_elements2, int given_array3[]){
	int i = 0, j = 0, k = 0;
	int flag;
	while (k < (no_of_elements1 + no_of_elements2)){
		if (given_array1[i] == given_array2[j]){
			given_array3[k++] = given_array1[i++];
			given_array3[k++] = given_array2[j++];
		}
		else if (given_array1[i] < given_array2[j]){
			if (i == (no_of_elements1 - 1)){
				given_array3[k++] = given_array1[i];
				flag = 1;
				break;
			}
			else
				given_array3[k++] = given_array1[i++];
		}
		else {
			if (j == (no_of_elements2 - 1)){
				given_array3[k++] = given_array2[j];
				flag = 0;
				break;
			}
			else
				given_array3[k++] = given_array2[j++];
		}
			
		//printf("i:%d j:%d k:%d\n", i, j, k);
	}
	if (flag == 1){
		while (k < (no_of_elements1 + no_of_elements2))
			given_array3[k++] = given_array2[j++];
	}
	else if (flag == 0){
		while (i < (no_of_elements1 + no_of_elements2))
			given_array3[k++] = given_array2[i++];
	}
	return;
}