#include<stdio.h>

unsigned int a1, a2, a3, MAX, a_max, rank, summa, cnt;
float x1, x2, x3, r1, r2, r3;
FILE *fid;

void main(){
	
	MAX = 1000;
	
	printf("Hello World!\n");
	
//	printf("Enter first number: ");
//	scanf("%f", &x1);
//	printf("Enter second number: ");
//	scanf("%f", &x2);
//	printf("Enter third number: ");
//	scanf("%f", &x3);
	x1 = 0.14; x2 = 0.38;
	
	printf("You entered x1 = %f, x2 = %f\n", x1, x2);
	printf("Calculating combinations...");
	
	fid = fopen("res3.txt", "w");
	fprintf(fid, "Numbers, %f, %f\n", x1, x2);
	
	cnt = 0;
	
	for(a1=1; a1<=MAX; a1++){
		for(a2=1; a2<=MAX; a2++){
				
				r1 = 10 * a1 * x1;
				r2 = 10 * a2 * x2;
				
				summa = (float) (a1 + a2);
				
				if(r1 > summa && r2 > summa){
					// find max of the three numbers that comprise the solution
					a_max = a1;
					if(a2 > a_max){a_max = a2;}

					// calculate ranking number
					rank = a1*a1 + a2*a2;
										
					fprintf(fid, "%d, %d, %d, %d\n", a1, a2, a_max, rank);
					cnt++;
				}
				
		}
	}
	
	printf("DONE!\nFound %d solutions!\n", cnt);
	fclose(fid);
	
}
