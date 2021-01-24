#include<stdio.h>
#include<graphics.h>

void drawEllipse(int h,int k,int a,int b){

	int x = 0;
	int y = b;
	int p;
	p = (b*b) + (1/4)*(a*a)-(a*b*b);
	
	do{
		delay(10);
		putpixel(h+x,k+y,WHITE);
		putpixel(h-x,k-y,WHITE);
		putpixel(h+x,k-y,WHITE);
		putpixel(h-x,k+y,WHITE);
		if(p<0){
			x = x+1;
			y = y;
			p = p + 2*x*b*b + b*b;
		}
		else{
			x = x+1;
			y = y-1;
			p = p + 2*x*b*b + b*b - 2*y*a*a;
		}
	}while(2*b*b*x<2*a*a*y);
	

	p = b*b*(x+1/2)*(x+1/2) + a*a*(y-1)*(y-1)-a*a*b*b;
	do{
		delay(10);

		putpixel(h+x,k+y,WHITE);
		putpixel(h-x,k-y,WHITE);
		putpixel(h+x,k-y,WHITE);
		putpixel(h-x,k+y,WHITE);
		if(p<0){
			x = x+1;
			y = y-1;
			p = p+2*x*b*b-2*y*a*a+a*a;
		}
		else{
			x = x;
			y = y-1;
			p = p -2*y*a*a + a*a;
		}
	}while(y!=0);		


}

int main(){
	initwindow(1920,1080);
	drawEllipse(500,500,200,100);
	getch();
}

