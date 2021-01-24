#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

int ox;
int oy;


void drawCircle(float x,float y){
	circle(x+200,y-200,100);
}

void rotation(float x,float y,float ang){
	
	float x_new = x*cos(ang) - y*sin(ang);
	float y_new = x*sin(ang) + y*cos(ang);
	cout<<"Before "<<endl; 
	cout<<x<<","<<y;
	
	cout<<endl<<"Center"<<endl;
	cout<<ox<<","<<oy<<endl;
	
	cout<<endl<<"After"<<endl;
	cout<<x_new<<","<<y_new;

	drawCircle(fabs(x_new)-ox,fabs(y_new));
}

int main(){
	initwindow(900,900);
	ox = getmaxx()/2;
	oy = getmaxy()/2;
	
	line(ox,0,ox,2*oy);
	line(0,oy,2*ox,oy);
	
	
	
	float x = ox+200;
	float y = oy-200;
	
	cout<<x<<","<<y<<endl;
	
	drawCircle(x-200,y+200);
	
	rotation(x,y,90);
	
	getch();
}


