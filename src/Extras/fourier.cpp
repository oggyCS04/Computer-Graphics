

#include "fourier.h"
#include <stdio.h>
#include <iostream>
#include <graphics.h>
#include <math.h>

fourier::fourier(){
	
	int gd=DETECT,gm;
	double x,y,k,n,w;
	
	printf("\n\nFourier Series\n\n");
	
	printf("Enter the value of n : ");
	std::cin>>n;
	
	printf("Enter the value of w(omega) : ");
	std::cin>>w;
	
	x=0.0;

	// Initializing graphics.
	initgraph(&gd,&gm,NULL);
	line(100,250,1000,250);
	line(150,100,150,400);
	
	
	do{
		y=0.0;
		for(int i=1;i<=n;){
			k = i*w*x ;
			y= y + ((4*50)/3.14)*(sin(k/100)/i);
			x= x+0.1;
			printf("%lf\t%lf\t%lf\t%lf\t%d\n",x,k,y,n,i);
			putpixel(x+150,y+250,GREEN);
			i=i+2;
		}
		putpixel(x+150,y+250,WHITE);
		printf("-------------------\n");
	}while(x<=628);
	
	
	delay(500000);
	closegraph();
	
//	do{
//		y=50*sin(x/20);
//		x= x+0.1;
//		printf("%lf\n",x);
//		putpixel(x+150,y+250,GREEN);
//	}while(x<=125.6);
}

