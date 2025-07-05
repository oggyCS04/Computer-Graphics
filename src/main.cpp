
#include "Lab1/dda.h"
#include "Lab1/bla.h"
#include "Lab2/mpc.h"
#include "Lab2/mpe.h"
#include "Lab2/con_mpc.h"
#include "Lab2/con_mpe.h"
#include "Extras/fourier.h"
#include<stdio.h>

int main(int argc, char const *argv[]){
	
	int s;
	
	printf("\n1. DDA\n2. BLA\n3. Midpoint Th. Circle\n4. Midpoint Th. Ellipse\n5. Concentric Circles\n6. Concentric Ellipses\n7. Fourier Series\n\n");
	printf("Input your choice : ");
	scanf("%d",&s);
	
	switch(s){
		case 1:{
			dda obj1;
			break;
		}
		case 2:{
			bla obj1;
			break;
		}
		case 3:{
			mpc obj1;
			break;
		}
		case 4:{
			mpe obj1;
			break;
		}
		case 5:{
			ConMpc obj1;
			break;
		}
		case 6:{
			ConMpe obj1;
			break;
		}
		case 7:{
			fourier obj1;
			break;
		}
		default:{
			printf("\n\nInvalid Choice\n");
		}
	}
	
	return 0;
}

