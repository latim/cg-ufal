#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include <math.h>

#define __WIDTH 800
#define __HEIGHT 800
#define __ZERO 10

#define XMEIO __ZERO+390
#define YMEIO __HEIGHT/2

#define PI 3.14159265

double angulo = 0;

double petalas[1][4] = {
    {__ZERO+390, __HEIGHT/2, __ZERO+390, __ZERO-10}
};

void _cabo(){
    glLineWidth(6);
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(petalas[0][0], petalas[0][1]);
        glVertex2d(petalas[0][2], petalas[0][3]);
    glEnd();
}

void girar(unsigned char key, int x, int y){
    int i;
    float alpha = 0.1;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    double oldx, oldy;
    double theta;
    switch(key){
        case 'g':
            angulo += 10;
            alpha += 0.1;
            theta = (double) angulo*PI/180.0;
            oldx = petalas[0][2];
            oldy = petalas[0][3];
            petalas[0][2] = __ZERO+390 + 800*cos(theta);
            petalas[0][3] = __ZERO-10 + 800*sin(theta);
        break;
    }

    glutPostRedisplay();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
   
   	_cabo();

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
    glutInitWindowSize(800, 800);
    glutCreateWindow("Teste de primitivas");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(girar);
    glutMainLoop();

    return 0;
}