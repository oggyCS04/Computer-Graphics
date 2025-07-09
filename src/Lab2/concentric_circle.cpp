

#include "con_mpc.h"
#include <stdio.h>
#include <graphics.h>
#include <math.h>


ConMpc::ConMpc(){

	float h,k,p0,xn,yn;
	float r[5];
	
	char colorsname[4] = {
        WHITE, RED, GREEN, BLUE
    };
    
	printf("\n\nConcentric Circles\n");        
	printf("- Compiled by Sagar Gupta\n\n");

	printf("Enter the center of circle (h,k)\n");
	scanf("%f %f",&h,&k);
	
	for (int i=0;i<4;i++){
	
	printf("Enter the radius of %d circle : ",i+1);
	scanf("%f",&r[i]);
	
	}	
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	
	for (int i=0;i<4;i++){
	
	p0 = 1-r[i];

	xn = 0;
	yn = r[i];
	printf("%f",p0);
	
	do{
		putpixel(xn+h,yn+k,colorsname[i]); // Octant-1
		putpixel(-xn+h,yn+k,colorsname[i]); // Octant-2
		putpixel(-yn+h,xn+k,colorsname[i]); // Octant-3
		putpixel(-yn+h,-xn+k,colorsname[i]); // Octant-4
		putpixel(-xn+h,-yn+k,colorsname[i]); // Octant-5
		putpixel(xn+h,-yn+k,colorsname[i]); // Octant-6
		putpixel(yn+h,-xn+k,colorsname[i]); // Octant-7
		putpixel(yn+h,xn+k,colorsname[i]); // Octant-8
		delay(10);
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
}
	delay(500000);
	closegraph();
}

