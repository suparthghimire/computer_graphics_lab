#include<GL/freeglut.h>


void display();

void init(){
	glClearColor(0.0,0.0,0.0,1.0);
}
void reshape(int,int);
void setup(){
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(800,800);
	glutCreateWindow("Simple OpenGL Application");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	init();
	glutMainLoop();
}

int main(int argc, char** argv){
	glutInit(&argc,argv);
	setup();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glPointSize(2.0);
	
	glBegin(GL_TRIANGLES);//F means float
		glVertex2f(3.0,5.0);
		glVertex2f(6.0,7.0);
	glEnd();
	
	
	glBegin(GL_LINES);
		glVertex2f(7.0,9.0);
		glVertex2f(-9.0,1.0);
	glEnd();
    glRectf(6.0,7.0,9.0,8.0);
    	
	glFlush();
}

void reshape(int w,int h){
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10,10,-10,10);
	glMatrixMode(GL_MODELVIEW);
}






