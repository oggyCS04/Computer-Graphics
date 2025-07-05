

#include "mpe.h"
#include <stdio.h>
#include<iostream>
#include <graphics.h>
#include <math.h>

mpe::mpe(){
	
	float h,k,a,b,p0,xn,yn;
	
	printf("\n\nMidpoint Theorem for Ellipse\n");
	printf("- Compiled by Sagar Gupta\n\n");

	printf("Enter the center of ellipse (h,k)\n");
	scanf("%f %f",&h,&k);

	printf("Enter the radius of ellipse(along x-axis)\n");
	scanf("%f",&a);
	
	printf("Enter the radius of ellipse(along y-axis)\n");
	scanf("%f",&b);
	
	p0 = b*b - a*a*b + ((a*a)/4);
	
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	
	// for region-1
	
	xn = 0;
	yn = b;
	printf("%f",p0);
	
	do{
		putpixel(xn+h,yn+k,WHITE); // Octant-1
		putpixel(-xn+h,yn+k,WHITE); // Octant-2
		putpixel(-xn+h,-yn+k,WHITE); // Octant-5
		putpixel(xn+h,-yn+k,WHITE); // Octant-6
		delay(100);
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
		putpixel(xn+h,yn+k,WHITE); // Octant-8
		putpixel(xn+h,-yn+k,WHITE); // Octant-7
		putpixel(-xn+h,-yn+k,WHITE); // Octant-4
		putpixel(-xn+h,yn+k,WHITE); // Octant-3
		delay(100);
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
	
	delay(500000);
	closegraph();
	
}

