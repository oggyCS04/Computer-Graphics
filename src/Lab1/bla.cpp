// BLA algorithm to draw a line.

// Including preprocessor directives.
#include "bla.h"
#include <stdio.h>
#include <graphics.h>
#include <math.h>

// Declaring main function.
bla::bla()
{
	// Declaring variables.
	float x1,y1,x2,y2,dx,dy;
	float m,p0;
	float temp;
	
	printf("\n\nBLA\n");
	printf("- Compiled by Sagar Gupta\n\n");

	// Asking for initial point.
	printf("Enter the initial point\n");
	scanf("%f %f",&x1,&y1);

	// Asking for final point.
	printf("Enter the final point\n");
	scanf("%f %f",&x2,&y2);
	
	if(y1>y2){
		temp = x1;
		x1 = x2;
		x2 = temp;
		
		temp = y1;
		y1 = y2;
		y2 = temp;
	}
	
	dy = y2-y1;
	dx = x2-x1;
	
	m = dy/dx;
	printf("\nslope(m) = %f\n\n",m);
	
	dx = fabs(dx);
	dy = fabs(dy);
	
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	putpixel(x1,y1,WHITE);
	

		if(m>=0){
			if(m<=1){
				p0 = 2*dy-dx;
				do{
					printf("%f",p0);
					if(p0 < 0){
						x1 += 1;
						p0 = p0 + 2*dy;
					}
					else{
						x1 += 1;
						y1 += 1;
						p0 = p0+2*dy-2*dx;
					}
					printf("\t\t%f\t\t%f\n",x1,y1);
					putpixel(x1,y1,WHITE);
					delay(20);
				}while(x1!=x2 || y1!=y2);
				
			}
			else{
				p0 = 2*dx-dy;
				do{
					printf("%f",p0);
					if(p0 < 0){
						y1 += 1;
						p0 = p0+2*dx;
					}
					else{
						x1 += 1;
						y1 += 1;
						p0 = p0+2*dx-2*dy;
					}
					printf("\t\t%f\t\t%f\n",x1,y1);
					putpixel(x1,y1,WHITE);
					delay(20);
				}while(x1!=x2 || y1!=y2);
			}
		}
		else{
			if(fabs(m)<=1){
				p0 = 2*dy-dx;
				do{
					printf("%f",p0);
					if(p0 < 0){
						x1 -= 1;
						p0 = p0 + 2*dy;
					}
					else{
						x1 -= 1;
						y1 += 1;
						p0 = p0+2*dy-2*dx;
					}
					printf("\t\t%f\t\t%f\n",x1,y1);
					putpixel(x1,y1,WHITE);
					delay(20);
				}while(x1!=x2 || y1!=y2);
				
			}
			else{
				p0 = 2*dx-dy;
				do{
					printf("%f",p0);
					if(p0 < 0){
						y1 += 1;
						p0 = p0+2*dx;
					}
					else{
						x1 -= 1;
						y1 += 1;
						p0 = p0+2*dx-2*dy;
					}
					printf("\t\t%f\t\t%f\n",x1,y1);
					putpixel(x1,y1,WHITE);
					delay(20);
				}while(x1!=x2 || y1!=y2);
			}
		}
			

	// Concluding the program.
	delay(500000);
	closegraph();
}


