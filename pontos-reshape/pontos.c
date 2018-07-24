#ifdef __APPLE__
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>

int points[1000][2];
int c = 0;

void plotPoint(int x, int y){
	glColor3f(1.0, 0.0, 0.4);
	glBegin(GL_POINTS);
		glVertex2f(x, glutGet(GLUT_WINDOW_HEIGHT) - y);
	glEnd();
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	if(c != 0){
		int i;
		for(i = 0; i < c; i++){
			plotPoint(points[i][0], points[i][1]);
		}
	}
	glFlush();
}

void init(void){
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(5.0);
}

void mouse(int button, int state, int x, int y){
		
	if(state == GLUT_DOWN && button == GLUT_LEFT_BUTTON){
		int x1 = x;
		int y1 = glutGet(GLUT_WINDOW_HEIGHT) - y;
		points[c][0] = x1;
		points[c][1] = y;
		c++; 
		plotPoint(x1, y);
	} 
	
	glFlush();
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho (0, w, 0, h, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(200, 200);
	glutCreateWindow("Exemplo");

	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);

	init();

	glutMainLoop();

	return 0;
}