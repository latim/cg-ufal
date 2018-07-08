#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#define __WIDTH 800
#define __HEIGHT 800
#define __ZERO 10

void _lines(){
    glBegin(GL_LINES);
        glVertex2f(__ZERO, __HEIGHT-9);
        glVertex2f(__ZERO+90, __HEIGHT-100);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(__ZERO+20, __HEIGHT-160);
        glVertex2f(__ZERO+90, __HEIGHT-120);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(__ZERO+120, __HEIGHT-9);
        glVertex2f(__ZERO+100, __HEIGHT-100);
    glEnd();
}

void _points(){
    glBegin(GL_POINTS);
        glVertex2f(__ZERO+270, __HEIGHT-9);
        glVertex2f(__ZERO+240, __HEIGHT-13);
        glVertex2f(__ZERO+250, __HEIGHT-20);
        glVertex2f(__ZERO+200, __HEIGHT-35);
        glVertex2f(__ZERO+200, __HEIGHT-50);
    glEnd();
}

void _line_strip(){
    glBegin(GL_LINE_STRIP);
        glVertex2f(__ZERO+300, __HEIGHT-35);
        glVertex2f(__ZERO+290, __HEIGHT-60);
        glVertex2f(__ZERO+300, __HEIGHT-90);
        glVertex2f(__ZERO+330, __HEIGHT-85);
        glVertex2f(__ZERO+340, __HEIGHT-60);
        glVertex2f(__ZERO+340, __HEIGHT-60);
    glEnd();
}

void _line_loop(){
    glBegin(GL_LINE_LOOP);
        glVertex2f(__ZERO+400, __HEIGHT-35);
        glVertex2f(__ZERO+390, __HEIGHT-60);
        glVertex2f(__ZERO+400, __HEIGHT-90);
        glVertex2f(__ZERO+430, __HEIGHT-85);
        glVertex2f(__ZERO+440, __HEIGHT-60);
        glVertex2f(__ZERO+440, __HEIGHT-60);
    glEnd();
}

void _triangles(){
    glBegin(GL_TRIANGLES);
        glVertex2f(__ZERO+30, __HEIGHT-200);
        glVertex2f(__ZERO, __HEIGHT-240);
        glVertex2f(__ZERO+40, __HEIGHT-230);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(__ZERO+70, __HEIGHT-170);
        glVertex2f(__ZERO+100, __HEIGHT-200);
        glVertex2f(__ZERO+70, __HEIGHT-230);
    glEnd();
}

void _triangles_strip(){
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(__ZERO+200, __HEIGHT-200);
        glVertex2f(__ZERO+220, __HEIGHT-230);
        glVertex2f(__ZERO+180, __HEIGHT-250);
        glVertex2f(__ZERO+170, __HEIGHT-170);
        glVertex2f(__ZERO+140, __HEIGHT-230);
        glVertex2f(__ZERO+180, __HEIGHT-250);
    glEnd();
}

void _quads(){
    glBegin(GL_QUADS);
        glVertex2f(__ZERO+100, __HEIGHT-300);
        glVertex2f(__ZERO+80, __HEIGHT-320);
        glVertex2f(__ZERO+90, __HEIGHT-360);
        glVertex2f(__ZERO+105, __HEIGHT-350);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(__ZERO+150, __HEIGHT-330);
        glVertex2f(__ZERO+145, __HEIGHT-290);
        glVertex2f(__ZERO+200, __HEIGHT-290);
        glVertex2f(__ZERO+200, __HEIGHT-340);
    glEnd();
}

void _quad_strip(){
    glBegin(GL_QUAD_STRIP);
        glVertex2f(__ZERO+300, __HEIGHT-300);
        glVertex2f(__ZERO+270, __HEIGHT-360);
        glVertex2f(__ZERO+320, __HEIGHT-340);
        glVertex2f(__ZERO+300, __HEIGHT-370);
        glVertex2f(__ZERO+300, __HEIGHT-300);
        glVertex2f(__ZERO+320, __HEIGHT-340);
        glVertex2f(__ZERO+350, __HEIGHT-270);
        glVertex2f(__ZERO+390, __HEIGHT-320);
    glEnd();
}

void _polygon(){
    glBegin(GL_POLYGON);
        glVertex2f(__ZERO+450, __HEIGHT-300);
        glVertex2f(__ZERO+400, __HEIGHT-360);
        glVertex2f(__ZERO+460, __HEIGHT-380);
        glVertex2f(__ZERO+480, __HEIGHT-370);
        glVertex2f(__ZERO+500, __HEIGHT-340);
        glVertex2f(__ZERO+470, __HEIGHT-290);
    glEnd();
}


void display(void){
    glClear(GL_COLOR_BUFFER_BIT); 
   
    _lines();
    _points();
    _line_strip();
    _line_loop();
    _triangles();
    _triangles_strip();
    _quad_strip();
    _polygon();

    glFlush();
}

void init(void){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutReshapeWindow(1000, 1000);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 800);
}

int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Teste de primitivas");
    glutInitWindowSize(800,800);

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}