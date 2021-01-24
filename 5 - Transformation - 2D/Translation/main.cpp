#include<stdio.h>
#include<stdio.h>

#include<graphics.h>
int tx = 500;
int ty = 500;


void translation(int x,int y){
	circle(x,y,100);
	circle(x+tx,y+ty,100);
}

int main(){
	initwindow(800,800);
	int xt = 100;
	int yt = 100;
	translation(xt,yt);
	
	getch();
}
