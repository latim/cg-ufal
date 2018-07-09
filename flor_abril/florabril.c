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

int angulo = 0;

int petalas[4][4] = {
    {__WIDTH-600, __HEIGHT-300, __WIDTH-600, __HEIGHT-500},
    {__WIDTH-200, __HEIGHT-300, __WIDTH-200, __HEIGHT-500},
    {__WIDTH-500, __HEIGHT-200, __WIDTH-300, __HEIGHT-200},
    {__WIDTH-500, __HEIGHT-600, __WIDTH-300, __HEIGHT-600}
};

void _cabo(){
    glLineWidth(6);
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(__ZERO+390, __HEIGHT/2);
        glVertex2f(__ZERO+390, __ZERO-10);
    glEnd();
}

void _petalas(){

    int i;
    float alpha = 0.1;
    for(i = 0; i < 4; i++){
        alpha += 0.1;
        glBegin(GL_TRIANGLES);
            glColor3f(0.5f, 0.0f + alpha, 0.0f + alpha);
            glVertex2f(XMEIO, YMEIO);
            glVertex2f(petalas[i][0], petalas[i][1]);
            glVertex2f(petalas[i][2], petalas[i][3]);
        glEnd();
    }

}

void girar(unsigned char key, int x, int y){
    int i;
    float alpha = 0.1;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

    switch(key){
        case 'g':
            angulo += 5;
            for(i = 0; i < 4; i++){
                alpha += 0.1;
                petalas[i][0] = petalas[i][0]*cos(angulo*(PI/180)) + petalas[i][1]*sin(angulo*(PI/180));
                petalas[i][1] = -petalas[i][0]*sin(angulo*(PI/180)) + petalas[i][1]*cos(angulo*(PI/180));
                petalas[i][2] = petalas[i][2]*cos(angulo*(PI/180)) + petalas[i][3]*sin(angulo*(PI/180));
                petalas[i][3] = -petalas[i][2]*sin(angulo*(PI/180)) + petalas[i][3]*cos(angulo*(PI/180));
            }
        break;
        case 'h':
            angulo *= -1;
            angulo += 5;
            for(i = 0; i < 4; i++){
                alpha += 0.1;
                petalas[i][0] = petalas[i][0]*cos(angulo*(PI/180)) + petalas[i][1]*sin(angulo*(PI/180));
                petalas[i][1] = -petalas[i][0]*sin(angulo*(PI/180)) + petalas[i][1]*cos(angulo*(PI/180));
                petalas[i][2] = petalas[i][2]*cos(angulo*(PI/180)) + petalas[i][3]*sin(angulo*(PI/180));
                petalas[i][3] = -petalas[i][2]*sin(angulo*(PI/180)) + petalas[i][3]*cos(angulo*(PI/180));
            }
        break;
    }

    glutPostRedisplay();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
   
    _cabo();
    _petalas();

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