#include<stdio.h>
#include<graphics.h>
#include<unistd.h>

void drawCircle(int a,int b,int r){
	int x = 0;
	int y = r;
	int p = 1-r;
	int count = 2;
	do{
		putpixel(a+x,b+y,WHITE);
		putpixel(a-x,b-y,WHITE);
		putpixel(a+y,b+x,WHITE);
		putpixel(a-y,b-x,WHITE);
		putpixel(a+x,b-y,WHITE);
		putpixel(a-x,b+y,WHITE);
		putpixel(a+y,b-x,WHITE);
		putpixel(a-y,b+x,WHITE);
		if(p<0){
			x=x+1;
			y=y;
			p=p+2*x+3;
		}
		else{
			x=x+1;
			y=y-1;
			p=p+2*(x-y)+5;
		}
	}while(x<y);
}

int main(){
	initwindow(1920,1080);
	drawCircle(500,500,100);
	getch();
}
