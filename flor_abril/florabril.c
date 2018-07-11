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

double petalas[4][4] = {
    {__WIDTH-600, __HEIGHT-300, __WIDTH-600, __HEIGHT-500},
    {__WIDTH-200, __HEIGHT-300, __WIDTH-200, __HEIGHT-500},
    {__WIDTH-500, __HEIGHT-200, __WIDTH-300, __HEIGHT-200},
    {__WIDTH-500, __HEIGHT-600, __WIDTH-300, __HEIGHT-600}
};

double originais[4][4] = {
    {__WIDTH-600, __HEIGHT-300, __WIDTH-600, __HEIGHT-500},
    {__WIDTH-200, __HEIGHT-300, __WIDTH-200, __HEIGHT-500},
    {__WIDTH-500, __HEIGHT-200, __WIDTH-300, __HEIGHT-200},
    {__WIDTH-500, __HEIGHT-600, __WIDTH-300, __HEIGHT-600}
};

void _cabo(){
    glLineWidth(6);
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(__ZERO+390, __HEIGHT/2);
        glVertex2d(__ZERO+390, __ZERO-10);
    glEnd();
}

void _petalas(){

    int i;
    float alpha = 0.1;
    for(i = 0; i < 4; i++){
        alpha += 0.1;
        glBegin(GL_TRIANGLES);
            glColor3f(0.5f, 0.0f, 0.0f);
            glVertex2d(XMEIO, YMEIO);
            glVertex2d(petalas[i][0], petalas[i][1]);
            glVertex2d(petalas[i][2], petalas[i][3]);
        glEnd();
    }

}

void girar(unsigned char key, int x, int y){
    int i;
    float alpha = 0.1;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    double new_x, new_y;
    double theta;
    switch(key){
        case 'g':
            angulo = 10;
            for(i = 0; i < 4; i++){
                theta = (double) angulo*PI/180.0;
                new_x = (XMEIO - petalas[i][0])*cos(theta) - (YMEIO - petalas[i][1])*sin(theta);
                new_y = (YMEIO - petalas[i][1])*cos(theta) + (XMEIO - petalas[i][0])*sin(theta);

                new_x += XMEIO;
                new_y += YMEIO;

                petalas[i][0] = new_x;
                petalas[i][1] = new_y;

                new_x = (XMEIO - petalas[i][2])*cos(theta) - (YMEIO - petalas[i][3])*sin(theta);
                new_y = (YMEIO - petalas[i][3])*cos(theta) + (XMEIO - petalas[i][2])*sin(theta);
                
                new_x += XMEIO;
                new_y += YMEIO;

                petalas[i][2] = new_x;
                petalas[i][3] = new_y;

            }
        break;

        case 'h':
            angulo = -10;
            for(i = 0; i < 4; i++){
                theta = (double) angulo*PI/180.0;
                new_x = (XMEIO - petalas[i][0])*cos(theta) - (YMEIO - petalas[i][1])*sin(theta);
                new_y = (YMEIO - petalas[i][1])*cos(theta) + (XMEIO - petalas[i][0])*sin(theta);

                new_x += XMEIO;
                new_y += YMEIO;

                petalas[i][0] = new_x;
                petalas[i][1] = new_y;

                new_x = (XMEIO - petalas[i][2])*cos(theta) - (YMEIO - petalas[i][3])*sin(theta);
                new_y = (YMEIO - petalas[i][3])*cos(theta) + (XMEIO - petalas[i][2])*sin(theta);
                
                new_x += XMEIO;
                new_y += YMEIO;

                petalas[i][2] = new_x;
                petalas[i][3] = new_y;

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