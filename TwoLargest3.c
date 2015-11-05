//finding two largest numbers in the given array(satisfying all conditions)and no duplicatess for largest 
#include<stdio.h>
void largest2(int * a);
void main() {
	int a[5] = { 90, 41, 34, 65, 65};
	//finding the largest and second largest numbers
	largest2(a);
	_getch();
}

void largest2(int * a) {
	//assigning the greater number among (a[0] and a[1]) to large and the remaining to large2 
	int large = ((a[0] > a[1]) ? a[0] : a[1]);
	int large2 = ((a[0] < a[1]) ? a[0] : a[1]);
	for (int i = 2; i < 5; i++){
		//checking with other elements in array
		if (large < a[i]) {
			large2 = large;
			large = a[i];
		}
		else if (large2 < a[i] && large != a[i]) {
			large2 = a[i];
		}
	}
	printf("great1:%d\tgreat2:%d\n", large, large2);
}