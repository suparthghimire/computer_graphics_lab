#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

int ox;
int oy;
void rotation(float x,float y,float ang){
	
	float x_new = x*cos(ang) - y*sin(ang);
	float y_new = x*sin(ang) + y*cos(ang);

	bar3d(fabs(x_new)-ox+200,fabs(y_new)-200,fabs(y_new)-100,fabs(y_new)-100,50,1);	
	
//	setcolor(RED);
//	line(ox,oy,x,y);
//	line(ox,oy,fabs(x_new)-ox+200,fabs(y_new)-200);	
}

int main(){
	initwindow(900,900);
	ox = getmaxx()/2;
	oy = getmaxy()/2;
	
	line(ox,0,ox,2*oy);
	line(0,oy,2*ox,oy);
	
	float x = ox+200;
	float y = oy-200;
		
	bar3d(x,y,x+100,y+100,50,1);	
	rotation(x,y,90);
	
	getch();
}


