#include<stdio.h>
#include<stdio.h>
#include<graphics.h>

void translation(int x,int y,int len,int sx,int sy,int sz){
	int offset = 200;
	bar3d(x+offset,y+offset,x+offset+len*sx,y+offset*sy,30*sz,1);
}
int main(){
	initwindow(800,800);
	int x = 200;
	int y = 200;
	int len = 100;
	bar3d(x,y,x+len,y+len,30,1);
	translation(x,y,len,2,2,2);
	getch();
	
}	
