#include <iostream>
#include <GL/glut.h>

int year = 0;
int day = 0;
int year2 = 0;
int day2 = 0;

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	glPushMatrix();
		glRotatef((GLfloat) year, 1.0, 0.0, 0.0);
		glRotatef((GLfloat) day, 0.0, 0.0, 1.0);
		glutWireSphere(1.0, 20, 16);
	glPopMatrix();

	glPushMatrix();
		glRotatef((GLfloat) year, 0.0, 1.0, 0.0);
		glTranslatef(2.0, 0.0, 0.0);
		glRotatef((GLfloat) day, 0.0, 1.0, 0.0);
		glutWireSphere(0.2, 10, 8);
	glPopMatrix();

	glPushMatrix();
		glRotatef((GLfloat) year2, 0.0, 1.0, 0.0);
		glTranslatef(-2.0, 0.0, 0.0);
		glRotatef((GLfloat) day2, 0.0, 1.0, 0.0);
		glutWireSphere(0.2, 10, 8);
	glPopMatrix();

	glPushMatrix();
		glRotatef((GLfloat) year2, 1.0, 0.0, 0.0);
		glTranslatef(-2.0, 0.0, 0.5);
		glRotatef((GLfloat) day2, 1.0, 0.0, 0.0);
		glutWireSphere(0.05, 10, 8);
	glPopMatrix();

	glPushMatrix();
		glRotatef((GLfloat) year2, 1.0, 1.0, 0.0);
		glTranslatef(-2.0, 0.0, -0.5);
		glRotatef((GLfloat) day2, 1.0, 1.0, 0.0);
		glutWireSphere(0.05, 10, 8);
	glPopMatrix();

	glutSwapBuffers();
}

void init(void){
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void keyboard(unsigned char key, int x, int y){
	switch(key){
		case 'd':
			day2 = (day2-10) % 360;
			day = (day+10) % 360;
			glutPostRedisplay();
		break;
		case 'D':
			day = (day-10) % 360;
			day2 = (day2+10) % 360;
			glutPostRedisplay();
		break;
		case 'y':
			year = (year+5) % 360;
			year2 = (year2-5) % 360;
			glutPostRedisplay();
		break;
		case 'Y':
			year2 = (year2+5) % 360;
			year = (year-5) % 360;
			glutPostRedisplay();
		break;
		case 27:
			exit(0);	
		break;
		default:
		break;
	}
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluPerspective(60.0, (GLfloat) w/ (GLfloat)h, 1.0, 20.0);
   gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}


int main(int argc, char **argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Rotação de planetas");

	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}