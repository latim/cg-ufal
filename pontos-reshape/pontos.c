#ifdef __APPLE__
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>

int points[1000][2];
int c = 0;

int x2, y2;

int pr = 0;

void plotPoint(int x, int y, float r, float g, float b, int line){
	glPointSize(line);

	glColor3f(r, g, b);
	glBegin(GL_POINTS);
		glVertex2f(x, y);
	glEnd();
	
	points[c][0] = x;
	points[c][1] = y;
	c++; 
	
	glFlush();
}

void bresenham(GLfloat x1, GLfloat x2,GLfloat y1, GLfloat y2, float r, float g, float b, int line){
    glLineWidth(line);
    glColor3f(r, g, b);
    GLfloat dx,dy,incE,incNE,d;
    int x,y,i;
    dx = x2-x1;
    dy = y2-y1;
    d = (2*dy)-dx;
    incE = 2*dy;
    incNE = 2*(dy-dx);
    x = x1;
    y = y1;
    plotPoint(x, y, r, g, b, line);
    if(dx == 0){
        for(i=y1;i<=y2;i++) plotPoint(x, i, r, g, b, line);
    }else if(dy == 0){
        for(i=x1;i<=x2;i++) plotPoint(i, y, r, g, b, line);
    }else{
        while(x <= x2){
            if(d <= 0){
                d += incE;
                x = x + 1;
            }else{
                d += incNE;
                x = x + 1;
                y = y + 1;
            }
            plotPoint(x, y, r, g, b, line);
        }
    }
}


void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	if(c != 0){
		int i;
		for(i = 0; i < c; i++){
			plotPoint(points[i][0], points[i][1], 1, 0, 0, 2);
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

		if(pr){
			bresenham(x2, x1, y2, y1, 1.0, 0.0, 0.0, 2);
			pr = 0;
		}else{
			x2 = x1;
			y2 = y1;
			pr = 1;
		}

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