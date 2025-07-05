


#include "con_mpe.h"
#include <stdio.h>
#include<iostream>
#include <graphics.h>
#include <math.h>

ConMpe::ConMpe(){
	
	float h,k,a,b,p0,xn,yn;
	float l[4],m[4];
	char colorsname[4] = {
        WHITE, RED, GREEN, BLUE
    };
	
	printf("\n\nConcentric Ellipes\n");
	printf("- Compiled by Sagar Gupta\n\n");

	printf("Enter the center of ellipse (h,k)\n");
	scanf("%f %f",&h,&k);
	
	for(int i=0;i<4;i++){
		
		printf("\nEnter the radius of %d ellipse(along x-axis) : ",i+1);
		scanf("%f",&l[i]);
		
		printf("Enter the radius of %d ellipse(along y-axis) : ",i+1);
		scanf("%f",&m[i]);
	}
	
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	
	for(int i=0;i<4;i++){
		a = l[i];
		b = m[i];
		p0 = b*b - a*a*b + ((a*a)/4);
		
		
		// for region-1
		
		xn = 0;
		yn = b;
		printf("%f",p0);
		
		do{
			putpixel(xn+h,yn+k,colorsname[i]); // Octant-1
			putpixel(-xn+h,yn+k,colorsname[i]); // Octant-2
			putpixel(-xn+h,-yn+k,colorsname[i]); // Octant-5
			putpixel(xn+h,-yn+k,colorsname[i]); // Octant-6
			delay(20);
			if(p0<0){
				xn += 1;
				p0 = p0 + 2*b*b*xn + b*b;
			}
			else{
				xn += 1;
				yn -= 1;
				p0 = p0 + 2*b*b*xn - 2*a*a*yn + b*b;
			}
			printf("\t%f\t%f\n%f",xn,yn,p0);
			
		}while((2*b*b*xn)<=(2*a*a*yn));
		
		// for region-2
		
		p0 = pow(b,2)*pow((xn+0.5),2) + pow(a,2)*pow((yn-1),2) - pow(a,2)*pow(b,2);
		printf("\n\n%f",p0);
		
		do{
			putpixel(xn+h,yn+k,colorsname[i]); // Octant-8
			putpixel(xn+h,-yn+k,colorsname[i]); // Octant-7
			putpixel(-xn+h,-yn+k,colorsname[i]); // Octant-4
			putpixel(-xn+h,yn+k,colorsname[i]); // Octant-3
			delay(20);
			if(p0<0){
				xn += 1;
				yn -= 1;
				p0 = p0 + 2*b*b*xn - 2*a*a*yn + a*a;
			}
			else{
				yn -= 1;
				p0 = p0 - 2*a*a*yn + a*a;
			}
			printf("\t%f\t%f\n%f",xn,yn,p0);
			
		}while(yn>=0);
	}
	delay(500000);
	closegraph();
	
}

