// DDA algorithm to draw a line.

// Including preprocessor directives.
#include "dda.h"
#include <stdio.h>
#include<iostream>
#include <graphics.h>
#include <math.h>

// Declaring main function.
dda::dda()
{
	// Declaring variables.
	float x1,y1,x2,y2,dx,dy;
	float m;
	bool check;
	
	printf("\n\nDDA\n");
	printf("- Compiled by Sagar Gupta\n\n");

	// Asking for initial point.
	printf("Enter the initial point\n");
	scanf("%f %f",&x1,&y1);

	// Asking for final point.
	printf("Enter the final point\n");
	scanf("%f %f",&x2,&y2);
	
	dy = y2-y1;
	dx = x2-x1;
	
	// Initializing graphics variables.
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	putpixel(x1,y1,WHITE);

	if(dx == 0){
		do{
			if(dy > 0){
				y1 += 1;
			}
			else{
				y1 -= 1;
			}
			printf("%f",y1);
			putpixel(x1,y1,WHITE);
			delay(20);
		}while(y1!=y2);
	}
	else{
		m = dy/dx;
		printf("%f",m);
		
		do{
			if(dx > 0){
				if(m==1){
				x1 += 1;
				y1 += 1;
				}
				else if (m>1){
					x1 += (1/m);
					y1 += 1;
				}
				else {
					x1 += 1;
					y1 += m;
				}
			}
			else if(dx < 0){
				if(m==1){
				x1 -= 1;
				y1 -= 1;
				}
				else if (m>1){
					x1 -= (1/m);
					y1 -= 1;
				}
				else {
					x1 -= 1;
					y1 -= m;
				}
			}
			putpixel(x1,y1,WHITE);
			delay(20);
		}while(round(x1)!=round(x2) || round(y1)!=round(y2));
	}	

	// Concluding the program.
	delay(500000);
	closegraph();
}


