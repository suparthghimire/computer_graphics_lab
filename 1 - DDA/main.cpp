#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>


void DDA(int x1,int y1,int x2,int y2){
	int dx,dy,steps,k;
	float incX,incY,x,y;
	dx = x2-x1;
	dy = y2-y1;
	if(abs(dx)>abs(dy)){
		steps = fabs(dx);
	}
	else{
		steps = fabs(dy);
	}
	incX = dx/steps;
	incY=dy/steps;
	x = x1;
	y = y1;
	putpixel(round(x),round(y),WHITE);
	printf(" x  |  y\n");
	printf("---------\n");
	printf("%0.0f | %0.0f\n",x,y);
	printf("---------\n");
	for(k=0;k<steps;k++){
		putpixel(round(x),round(y),WHITE);
		x = x + incX;
		y = y + incY;
		printf("%0.0f | %0.0f\n",x,y);
		printf("---------\n");
		delay(10);
	}
	printf("Line Drawn!!!!!!");
	
}

main(){
	initwindow(800,800);
	DDA(600,600,400,400);
	getch();
}
