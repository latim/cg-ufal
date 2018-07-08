#ifdef __APPLE__
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

void lineSegment(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(0,0);
	glVertex2i(200, 150);
	glEnd();
	glFlush();
}

void init(void){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

int main(int argc, char **argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Exemplo");
	glutInitWindowSize(500, 500);

	init();

	glutDisplayFunc(lineSegment);

	glutMainLoop();

return 0;
}