#include<stdio.h>
#include<stdio.h>
#include<graphics.h>

void translation(int x,int y,int len,int tx,int ty){
	bar3d(x+tx,y+ty,x+tx+len,y+ty+len,30,1);
}
int main(){
	initwindow(800,800);
	int x = 200;
	int y = 200;
	int len = 100;
	bar3d(x,y,x+len,y+len,30,1);
	translation(x,y,len,300,300);
	getch();
	
}	
