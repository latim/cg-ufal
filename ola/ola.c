#ifdef __APPLE__
	#include <GLUT/glut.h> 
#else
	#include <GL/glut.h> 
#endif

#include <math.h>

#define INICIO_X 100
#define INICIO_Y 20

#define PI 3.1415926

double quadrados[4][8] = {
	{
		INICIO_X,
		INICIO_Y,
		INICIO_X + 50,
		INICIO_Y,
		INICIO_X + 50,
		INICIO_Y + 50,
		INICIO_X,
		INICIO_Y + 50
	},
	{
		INICIO_X + 70,
		INICIO_Y,
		INICIO_X + 120,
		INICIO_Y,
		INICIO_X + 120,
		INICIO_Y + 50,
		INICIO_X + 70,
		INICIO_Y + 50
	},
	{
		INICIO_X + 140,
		INICIO_Y,
		INICIO_X + 190,
		INICIO_Y,
		INICIO_X + 190,
		INICIO_Y + 50,
		INICIO_X + 140,
		INICIO_Y + 50
	},
	{
		INICIO_X + 210,
		INICIO_Y,
		INICIO_X + 260,
		INICIO_Y,
		INICIO_X + 260,
		INICIO_Y + 50,
		INICIO_X + 210,
		INICIO_Y + 50
	}
};

int x_distancias_centros[4] = {
	0,
	70,
	140,
	210
};

int y_distancias_centros[4] = {
	0,
	0,
	0,
	0
};

int fila_fake_ordem[4] = {
	0,
	1,
	2,
	3
};

int subir[4] = {
	1,
	1,
	1,
	1
};

int movimento = -1;

void _circulos() {

	int i, j;
	double x_centro = 125;
	double y_centro = 95;
	double raio = 23;

	for (j = 0; j < 4; j++) {
		glBegin(GL_POINTS);

		for (i = 0; i < 360; i++) {

			double theta = (2 * PI * i) / 360;

			double x = x_centro + x_distancias_centros[j] + raio * cos(theta);
			double y = y_centro + y_distancias_centros[j] + raio * sin(theta);

			glVertex2d(x, y);
		}

		glEnd();
	}
}

void _quadrados() {

	int i;

	for (i = 0; i < 4; i++) {
		glBegin(GL_QUADS);
		glVertex2d(quadrados[i][0], quadrados[i][1]);
		glVertex2d(quadrados[i][2], quadrados[i][3]);
		glVertex2d(quadrados[i][4], quadrados[i][5]);
		glVertex2d(quadrados[i][6], quadrados[i][7]);
		glEnd();
	}
}

void mover(int primeiro) {
	if (y_distancias_centros[fila_fake_ordem[0]] < 60 && subir[fila_fake_ordem[0]]) {
		if (fila_fake_ordem[0] == primeiro) {
			y_distancias_centros[fila_fake_ordem[0]] += 20;
			quadrados[fila_fake_ordem[0]][1] += 20;
			quadrados[fila_fake_ordem[0]][3] += 20;
			quadrados[fila_fake_ordem[0]][5] += 20;
			quadrados[fila_fake_ordem[0]][7] += 20;
		} else {
			if (subir[fila_fake_ordem[3]] == 0) {
				quadrados[fila_fake_ordem[0]][1] += 5;
				quadrados[fila_fake_ordem[0]][3] += 5;
				quadrados[fila_fake_ordem[0]][5] += 5;
				quadrados[fila_fake_ordem[0]][7] += 5;
				y_distancias_centros[fila_fake_ordem[0]] += 5;
			} else {
				int diff = (y_distancias_centros[fila_fake_ordem[3]] - y_distancias_centros[fila_fake_ordem[0]]) - 5;
				quadrados[fila_fake_ordem[0]][1] += diff;
				quadrados[fila_fake_ordem[0]][3] += diff;
				quadrados[fila_fake_ordem[0]][5] += diff;
				quadrados[fila_fake_ordem[0]][7] += diff;
				y_distancias_centros[fila_fake_ordem[0]] += diff;
			}
		}
	} else if (y_distancias_centros[fila_fake_ordem[0]] > 0) {
		y_distancias_centros[fila_fake_ordem[0]] -= 10;
		quadrados[fila_fake_ordem[0]][1] -= 10;
		quadrados[fila_fake_ordem[0]][3] -= 10;
		quadrados[fila_fake_ordem[0]][5] -= 10;
		quadrados[fila_fake_ordem[0]][7] -= 10;
		if (y_distancias_centros[fila_fake_ordem[0]] < 0) {
			y_distancias_centros[fila_fake_ordem[0]] = 0;
			quadrados[fila_fake_ordem[0]][1] = 0;
			quadrados[fila_fake_ordem[0]][3] = 0;
			quadrados[fila_fake_ordem[0]][5] = 0;
			quadrados[fila_fake_ordem[0]][7] = 0;
		}
	}

	if (y_distancias_centros[fila_fake_ordem[0]] == 60) {
		subir[fila_fake_ordem[0]] = 0;
	}

	for (int i = 0; i < 3; i++) {
		int aux = fila_fake_ordem[i];
		fila_fake_ordem[i] = fila_fake_ordem[i + 1];
		fila_fake_ordem[i + 1] = aux;
	}

	if(movimento == 1){
		if (fila_fake_ordem[0] == 3 && !subir[fila_fake_ordem[0]] && y_distancias_centros[fila_fake_ordem[0]] == 0) {
			for (int i = 0; i < 4; i++) {
				fila_fake_ordem[i] = i;
				subir[i] = 1;
				movimento = -1;
			}
		}
	}else if(movimento == 0){
		if (fila_fake_ordem[0] == 0 && !subir[fila_fake_ordem[0]] && y_distancias_centros[fila_fake_ordem[0]] == 0) {
			for (int i = 0; i < 4; i++) {
				fila_fake_ordem[i] = i;
				subir[i] = 1;
				movimento = -1;
			}
		}
	}
}

void andar(unsigned char key, int x, int y) {

	switch (key) {
		case 'g':
			if(movimento == -1 || movimento == 0){
				for (int i = 0; i < 4; i++) {
					fila_fake_ordem[i] = i;
					subir[i] = 1;
				}
				movimento = 1;
			}
			mover(0);
			break;
		case 'h':
			if(movimento == -1 || movimento == 1){
				fila_fake_ordem[0] = 3;
				fila_fake_ordem[1] = 2;
				fila_fake_ordem[2] = 1;
				fila_fake_ordem[3] = 0;
				subir[0] = subir[1] = subir[2] = subir[3] = 1;
				movimento = 0;
			}
			mover(3);
			break;
	}

	glutPostRedisplay();
}

void _msg(char* s){
	glRasterPos2f(200, 400);
	int len = (int) strlen(s);

	for(int i = 0; i < len; i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
	}
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	_msg("Pressione G ou H para fazer a OLA");
	_quadrados();
	_circulos();

	glFlush();
}

void init(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glutReshapeWindow(800, 800);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 800);
}

int main(int argc, char ** argv) {

	glutInit( & argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Ola");

	init();

	glutDisplayFunc(display);
	glutKeyboardFunc(andar);
	glutMainLoop();

	return 0;
}