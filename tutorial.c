#include<stdio.h>

float a1, a2, a3, a4, a5, a6;
int i;

void main(){
	
	a1 = 5;
	a2 = 3;
	a3 = a1 + a2;
	
	printf("bkasjdf aksjdhf kajsdfh gakjs gfakjs\n\n");
	printf("Result is: %f and thank you %f\n", a3, a1);
	
	a5 = 0;
	for(i=1; i<=100; i++){
		a5 = a5 + i;
		
		if(a5 > 4000){
			printf("pipa");
		}
	}

	printf("Result is = %f\n", a5);
	
}
