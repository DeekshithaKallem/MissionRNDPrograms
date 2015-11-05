#include <stdio.h>
int lcm(int[]);
int main(){
	int given_array[4];
	printf("Enter four numbers\n");
	for(int i = 0; i < 4; i++)
		scanf("%d", &given_array[i]);
	int lcm_of_nos =  lcm(given_array);
	printf("LCM is %d\n", lcm_of_nos);
	return 0;}
	int lcm(int given_array[4]){
		int large = given_array[0];
		for(int i = 1; i < 4; i++){
			if(given_array[i] > large)
				large = given_array[i];
		}
		while(1){
			if(large % given_array[0] == 0 && large % given_array[1] == 0 && large % given_array[2] == 0 && large % given_array[3] == 0)
			{
				return large;
			}
			large++;
		}
	}