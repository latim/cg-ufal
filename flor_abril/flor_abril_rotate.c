#ifdef __APPLE__
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

int angle = 0;

void init (void)
{
    /* selecionar cor de fundo (preto) */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    
    glMatrixMode(GL_PROJECTION); //Projecao 2D
    
    glOrtho(0.0, 500.0, 0.0, 400.0, -1.0, 1.0); //Definindo os limites da Porta de Visao (ViewPort)
}

void display(void)
{
    /* Limpar todos os pixels  */
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, .0);
    glBegin(GL_POLYGON);
        glVertex3f (249.0f, 250.0f, -1.0f);
        glVertex3f (251.0f, 250.0f, -1.0f);
        glVertex3f (249.0f, 100.0f, -1.0f);
        glVertex3f (251.0f, 100.0f, -1.0f);
    glEnd();
    
    /* Desenhar um polígono branco  */
    glPushMatrix();
    glColor3f (1.0, 1.0, 1.0);
    glTranslatef(250.0f, 250.0f, 0.0f);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glTranslatef(-250.0f, -250.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f (250.0f, 250.0f);
        glVertex2f (230.0f, 200.0f);
        glVertex2f (270.0f, 200.0f);
    glEnd();
    glPopMatrix();
    
    /* Desenhar um polígono vermelho */
    glPushMatrix();
    glColor3f (1.0, 0.0, 0.0);
    glTranslatef(250.0f, 250.0f, 0.0f);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glTranslatef(-250.0f, -250.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f (250.0f, 250.0f);
        glVertex2f (300.0f, 230.0f);
        glVertex2f (300.0f, 270.0f);
    glEnd();
    glPopMatrix();

    /* Desenhar um polígono verde */
    glPushMatrix();
    glColor3f (0.0, 1.0, 0.0);
    glTranslatef(250.0f, 250.0f, 0.0f);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glTranslatef(-250.0f, -250.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f (250.0f, 250.0f);
        glVertex2f (230.0f, 300.0f);
        glVertex2f (270.0f, 300.0f);
    glEnd();
    glPopMatrix();
    
    /* Desenhar um polígono vermelho */
    glPushMatrix();
    glColor3f (0.0, 0.0, 1.0);
    glTranslatef(250.0f, 250.0f, 0.0f);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glTranslatef(-250.0f, -250.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f (250.0f, 250.0f);
        glVertex2f (200.0f, 270.0f);
        glVertex2f (200.0f, 230.0f);
    glEnd();
    glPopMatrix();
    
    
    /* Não esperar! */
    glFlush ();
}

void keyboard(unsigned char key, int x, int y){
	switch(key){
		case 'd':
			angle += 10;
			glutPostRedisplay();
		break;
        case 'f':
			angle -= 10;
			glutPostRedisplay();
		break;
		default:
		break;
	}
}


int main(int argc, char** argv) {
    
	glutInit(&argc, argv);
    
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 400);
	glutInitWindowPosition (200, 200);
	glutCreateWindow ("Flor de Abril");
    
	init ();
    
	glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    
	glutMainLoop();
    
	/* C ANSI requer que main retorne um inteiro */
	return 0;
    
}