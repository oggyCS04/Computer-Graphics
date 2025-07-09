

#include "mpc.h"
#include <stdio.h>
#include <graphics.h>
#include <math.h>

mpc::mpc(){
	
	float h,k,r,p0,xn,yn;
	
	printf("\n\nMidpoint Theorem for Circle\n");
	printf("- Compiled by Sagar Gupta\n\n");

	printf("Enter the center of circle (h,k)\n");
	scanf("%f %f",&h,&k);

	printf("Enter the radius of circle\n");
	scanf("%f",&r);
	
	p0 = 1-r;
	
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	
	xn = 0;
	yn = r;
	printf("\n\n%f",p0);
	
	do{
		putpixel(xn+h,yn+k,WHITE); // Octant-1
		putpixel(-xn+h,yn+k,WHITE); // Octant-2
		putpixel(-yn+h,xn+k,WHITE); // Octant-3
		putpixel(-yn+h,-xn+k,WHITE); // Octant-4
		putpixel(-xn+h,-yn+k,WHITE); // Octant-5
		putpixel(xn+h,-yn+k,WHITE); // Octant-6
		putpixel(yn+h,-xn+k,WHITE); // Octant-7
		putpixel(yn+h,xn+k,WHITE); // Octant-8
		delay(50);
		if(p0<0){
			xn += 1;
			p0 = p0 + 2*xn + 1;
		}
		else{
			xn += 1;
			yn -= 1;
			p0 = p0 + 2*xn - 2*yn + 1;
		}
		printf("\t%f\t%f\n%f",xn,yn,p0);
	}while(xn<=yn);
	
	delay(500000);
	closegraph();
}

