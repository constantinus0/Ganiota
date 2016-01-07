#include<stdio.h>

unsigned int a1, a2, a3, MAX, a_max, rank, cnt;
float x1, x2, x3, r1, r2, r3, summa;
FILE *fid;

void main(){
	
	MAX = 1500;
	
	printf("Enter first number: ");
	scanf("%f", &x1);
	printf("Enter second number: ");
	scanf("%f", &x2);
	printf("Enter third number: ");
	scanf("%f", &x3);
	
	printf("You entered x1 = %f, x2 = %f, x3 = %f\n", x1, x2, x3);
	printf("Calculating combinations...");
	
	fid = fopen("apotelesmata.txt", "w");
	fprintf(fid, "Numbers, %f, %f, %f\n", x1, x2, x3);
	
	cnt = 0;
	
	for(a1=1; a1<=MAX; a1++){
		r1 = 10 * a1 * x1;
		
		for(a2=1; a2<=MAX; a2++){
			r2 = 10 * a2 * x2;
			
			for(a3=1; a3<=MAX; a3++){
				r3 = 10 * a3 * x3;
				summa = (float) (a1 + a2 + a3);
				
				if(r1 > summa && r2 > summa && r3 > summa){
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
