#include<stdio.h>
#include<stdio.h>
#include<graphics.h>
	int sx = 2;
	int sy = 2;
	
int sm [2][2]= {sx,0,0,sy};

void scaleMul(int s[2][2], int p[2][1]){
	int i,j,k;
	int temp[2][1] = {0};
	for(i=0;i<2;i++){
		for(j=0;j<1;j++){
			for(k=0;k<2;k++){
				temp[i][j] += s[i][k] * p[k][j];
			}
		}
	}
	p[0][0] = temp[0][0];//sxaled x coordinate
	p[1][0] = temp[1][0];//scaled y coordinate
}


void scaling(int x[],int y[]){
//	draw a triangle
	line(x[0],y[0],x[1],y[1]);
	line(x[1],y[1],x[2],y[2]);
	line(x[2],y[2],x[0],y[0]);
	
	int p[2][1];
	int i;

	for(i=0;i<3;i++){
		p[0][0] = x[i];
		p[1][0] = y[i];
	
		//scale the points
		scaleMul(sm,p);
		x[i] = p[0][0];
		y[i] = p[1][0];
		
	}
	line(x[0],y[0],x[1],y[1]);
	line(x[1],y[1],x[2],y[2]);
	line(x[2],y[2],x[0],y[0]);
}

int main(){
	initwindow(1920,1080);
	int x[] = {100,200,300};
	int y[] = {200,100,200};

	
	scaling(x,y);
	getch();
	
}
