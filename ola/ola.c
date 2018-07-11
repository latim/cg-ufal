#ifdef __APPLE__
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include <math.h>

#define INICIO_X 100
#define	INICIO_Y 20

#define PI 3.1415926

double quadrados[4][8] = {
	{INICIO_X, INICIO_Y, INICIO_X+50, INICIO_Y, INICIO_X+50, INICIO_Y+50, INICIO_X, INICIO_Y+50},
	{INICIO_X+70, INICIO_Y, INICIO_X+120, INICIO_Y, INICIO_X+120, INICIO_Y+50, INICIO_X+70, INICIO_Y+50},
	{INICIO_X+140, INICIO_Y, INICIO_X+190, INICIO_Y, INICIO_X+190, INICIO_Y+50, INICIO_X+140, INICIO_Y+50},
	{INICIO_X+210, INICIO_Y, INICIO_X+260, INICIO_Y, INICIO_X+260, INICIO_Y+50, INICIO_X+210, INICIO_Y+50}
};

int x_distancias_centros[4] = {0, 70, 140, 210};

int y_distancias_centros[4] = {0, 0, 0, 0};

int fila_fake_ordem[4] = {0, 1, 2, 3};

void _circulos(){

	int i, j;
	double x_centro = 125;
	double y_centro = 95;
	double raio = 23;

	for(j = 0; j < 4; j++){
		glBegin(GL_POINTS);

		for(i = 0; i < 360; i++){

			double theta = (2*PI*i)/360;

			double x = x_centro + x_distancias_centros[j] + raio*cos(theta);
			double y = y_centro + y_distancias_centros[j] + raio*sin(theta);

			glVertex2d(x, y);
		}

		glEnd();
	}
}

void _quadrados(){

	int i;

	for(i = 0; i < 4; i++){
		glBegin(GL_QUADS);
			glVertex2d(quadrados[i][0], quadrados[i][1]);
			glVertex2d(quadrados[i][2], quadrados[i][3]);
			glVertex2d(quadrados[i][4], quadrados[i][5]);
			glVertex2d(quadrados[i][6], quadrados[i][7]);
		glEnd();
	}
}

void andar(unsigned char key, int x, int y){

	switch(key){

		case 'g':
			if(y_distancias_centros[fila_fake_ordem[0]] < 155){
				y_distancias_centros[fila_fake_ordem[0]] += 20;
			} else {
				y_distancias_centros[fila_fake_ordem[0]] -= 20;
			}

			for(int i = 0; i < 3; i++){
				int aux = fila_fake_ordem[i];
				fila_fake_ordem[i] = fila_fake_ordem[i+1];
				fila_fake_ordem[i+1] = aux;
			}

		break;

	}

	glutPostRedisplay();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT); 
   	
    _quadrados();
    _circulos();

    glFlush();
}

void init(void){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutReshapeWindow(800, 800);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 800);
}

int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,800);
    glutCreateWindow("Ola");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(andar);
    glutMainLoop();

    return 0;
}