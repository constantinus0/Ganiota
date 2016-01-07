#include<stdio.h>

unsigned int a1, a2, a3, MAX, a_max, rank, cnt;
float x1, x2, x3, r1, r2, r3;
FILE *fid;

void main(){
	
	MAX = 3000;
	
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
	
	fid = fopen("res.txt", "w");
	fprintf(fid, "Numbers, %f, %f, %f\n", x1, x2, x3);
	
	cnt = 0;
	
	for(a1=1; a1<=MAX; a1++){
		for(a2=1; a2<=MAX; a2++){
			for(a3=1; a3<=MAX; a3++){
				
				r1 = (1 + ((float) a2) / ((float) a1) + ((float) a3) / ((float) a1)) / 10;
				r2 = (1 + ((float) a1) / ((float) a2) + ((float) a3) / ((float) a2)) / 10;
				r3 = (1 + ((float) a1) / ((float) a3) + ((float) a2) / ((float) a3)) / 10;
				
				if(x1 > r1 && x2 > r2 && x3 > r3){
					// find max of the three numbers that comprise the solution
					a_max = a1;
					if(a2 > a_max){a_max = a2;}
					if(a3 > a_max){a_max = a3;}

					// calculate ranking number
					rank = a1*a1 + a2*a2 + a3*a3;
										
					fprintf(fid, "%d, %d, %d, %d, %d\n", a1, a2, a3, a_max, rank);
					cnt++;
				}
				
			}
		}
	}
	
	printf("DONE!\nFound %d solutions!\n", cnt);
	fclose(fid);
	
}
