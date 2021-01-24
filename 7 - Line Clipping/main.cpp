#include <iostream>
#include <string>
#include <math.h>
#include<graphics.h>
using namespace std;
int xmin = 200,ymin = 200,xmax = 600,ymax = 600;
int bin_to_str(char c[]){
	int num = 0,j = 3;
	for(int i=0;i<4;i++)
    	num += pow(2,j--)*(c[i] - '0');
    return num;
}
int check_partially_inside(int x, int y) {
	char c[4];
	c[0] = (x<xmin)?'1':'0';
	c[1] = (x>xmax)?'1':'0';
	c[2] = (y<ymin)?'1':'0';
	c[3] = (y>ymax)?'1':'0'; 
	return bin_to_str(c);
}
struct coord{
	float x1,x2,y1,y2;
};
struct coord clip(int x1,int y1, int x2,int y2){
	float new_x = x1,new_y = y1;
	
	if(x2-x1 == 0){
		if(y1<=ymin) new_y = ymin;
		else new_y = ymax;
	}
	else{
		float m = ((float)y2-y1)/((float)x2-x1);
		if(x1<=xmin || x1>xmax){
			if(x1<=xmin) new_x = xmin;
			else new_x = xmax;
			new_y = (float)y1 + (float)m*((float)new_x-x1);	
		}
		if(new_y<=ymin || new_y>ymax){
			if(y1<=ymin) new_y = ymin;
			else new_y = ymax;
			new_x = (float)x1 + (1/(float)m)*((float)new_y-y1);
		}		
	}
	
	struct coord c;
	c.x1 = new_x;
	c.y1 = new_y;
	c.x2 = x2;
	c.y2 = y2;
	return c;
}

int main(){
	initwindow(800,800);	
	
	line(0,ymin,getmaxx(),ymin);
	line(0,ymax,getmaxx(),ymax);
	
	line(xmin,0,xmin,getmaxy());
	line(xmax,0,xmax,getmaxy());
	
	int x1 = 10, y1=20;
	int x2 = 700,y2=800;
	
	int r1 = check_partially_inside(x1,y1);
	int r2 = check_partially_inside(x2,y2);
	
	if((r1 | r2)== 0){
		line(x1,y1,x2,y2);
	}
	else{
		if((r1 & r2) == 0){
			if(r1!=0){
				struct coord c = clip(x1,y1,x2,y2);
				x1 = c.x1;
				y1 = c.y1;
				x2 = c.x2;
				y2 = c.y2;
			}
			if(r2!=0){
				struct coord c = clip(x2,y2,x1,y1);
				x1 = c.x1;
				y1 = c.y1;
				x2 = c.x2;
				y2 = c.y2;
				
			}
			line(x1,y1,x2,y2);
		}
		else cout<<"Line is completely outside"<<endl;
	}
	getch();
}

