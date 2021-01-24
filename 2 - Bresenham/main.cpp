#include<stdio.h>
#include<graphics.h>
#include<unistd.h>


void bresenham(int x1,int y1,int x2,int y2){
	int x,y;
	x = x1;
	y = y1;
	int dx,dy;
	
	dx = x2-x1;dy=y2-y1;
	
	int color = 0;
	
	int p = 2*dy - dx;
	
	printf(" x  |  y\n");
	printf("---------\n");
	while(x<=x2){
		delay(10);
		putpixel(x,y,WHITE);
		printf("%d | %d\n",x,y);
		printf("---------\n");
		x++;
		color++;
		if(p<0)
			p+=2*dy;
		else{
			p+=2*dy-2*dx;
			y++;
		}
	}
	printf("\nLine Drawn!");
}

int main(){
	initwindow(800,800);
	setbkcolor(WHITE);
	bresenham(400,400,600,600);
	getch();
}
