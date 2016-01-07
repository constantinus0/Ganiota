#include<stdio.h>

unsigned int a1, a2, a3, MAX, a_max, rank, summa, cnt;
float x1, x2, x3, r1, r2, r3;
FILE *fid;

void main(){
	
	MAX = 6000;
	
	printf("Hello World!\n");
	
//	printf("Enter first number: ");
//	scanf("%f", &x1);
//	printf("Enter second number: ");
//	scanf("%f", &x2);
//	printf("Enter third number: ");
//	scanf("%f", &x3);
	x1 = 0.19; x2 = 0.36; x3 = 0.51;
	
	printf("You entered x1 = %f, x2 = %f, x3 = %f\n", x1, x2, x3);
	printf("Calculating combinations...");
	
	fid = fopen("res2.txt", "w");
	fprintf(fid, "Numbers, %f, %f, %f\n", x1, x2, x3);
	
	cnt = 0;
	
	for(a1=10000; a1>MAX; a1--){
		for(a2=10000; a2>MAX; a2--){
			for(a3=10000; a3>MAX; a3--){
				
				r1 = a1 * x1;
				r2 = a2 * x2;
				r3 = a3 * x3;
				summa = (float) (a1 + a2 + a3) / 10.0;
				
				if(r1 > summa && r2 > summa && r3 > summa){
					// find max of the three numbers that comprise the solution
					a_max = a1;
					if(a2 > a_max){a_max = a2;}
					if(a3 > a_max){a_max = a3;}

					// calculate ranking number
					rank = a1*a1 + a2*a2 + a3*a3;
										
					//fprintf(fid, "%d, %d, %d, %d, %d\n", a1, a2, a3, a_max, rank);
					cnt++;
				}
				
			}
		}
	printf("%d, ", a1);
	}
	
	printf("DONE!\nFound %d solutions!\n", cnt);
	fclose(fid);
	
}
