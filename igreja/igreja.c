#include <stdio.h>
#ifdef __APPLE__
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif
#include <math.h>

#define COLOR_WALL_X 0.917
#define COLOR_WALL_Y 0.8431
#define COLOR_WALL_Z 0.7372

#define COLOR_DOOR_X 0.4
#define COLOR_DOOR_Y 0.8
#define COLOR_DOOR_Z 0.7

#define DEBUG 1

#define PI 3.14

GLint WIDTH = 700;
GLint HEIGHT = 700;

//float lx = 0.0f, lz = -1.0f;
//float x = 5.0f, z = 20.0f, y = 1.0f;

float lx = 0.0f, lz = -1.0f;
//float x = 4.609134f, z = 46.560791f, y = 1.0f;
float x = 4.609134, z = 26.560791f, y = 1.0f;

GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light_position[] = {0.0, 0.0, 0.0, 1.0};

float angle = 0.0f;

float angle_porta = 0;

float debugx = 5.875443f;
void drawTemple() {

    glPushMatrix();
		glTranslatef(0.0f, 2.0f, 1.0f); 
		glScalef(10.0, 12.0, 1.0);  
		glColor3f(COLOR_WALL_X, COLOR_WALL_Y, COLOR_WALL_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	float a = 2.0f;
	float y = 15.690016;
	float z = 4.309961f;
	float x = 5.000023f;

	glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
		 	glVertex3f(x, y, z);   //V0(red)
			glVertex3f(-a+x,-a+y, a+z);   //V1(green)
			glVertex3f( a+x,-a+y, a+z);   //V2(blue)
			glVertex3f( a+x,-a+y,-a+z);   //V3(green)
			glVertex3f(-a+x,-a+y,-a+z);   //V4(blue)
			glVertex3f(-a+x,-a+y, a+z);   //V1(green)
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(5.0f, 15.0f, 1.0f); 
		glScalef(0.5, 15.0, 1.0);  
		glColor3f(COLOR_DOOR_X, COLOR_DOOR_Y, COLOR_DOOR_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(5.0f, 17.840065f, 1.0f); 
		glScalef(6.0, 1.0, 1.0);  
		glColor3f(COLOR_DOOR_X, COLOR_DOOR_Y, COLOR_DOOR_Z);
		glutSolidCube(0.3);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(5.0f, 10.0f, 1.0f); 
		glScalef(8.0, 20.0, 10.0);  
		glColor3f(COLOR_DOOR_X, COLOR_DOOR_Y, COLOR_DOOR_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(5.0f, 8.7f, 1.0f);
		glScalef(15.0, 15.0, 10.0);  
		glColor3f(COLOR_DOOR_X, COLOR_DOOR_Y, COLOR_DOOR_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	//Bordas da porta

	glPushMatrix();
		glTranslatef(2.839999f, 2.0f, 9.0f); 
		glScalef(1.5, 12.0, 0.5);  
		glColor3f(COLOR_WALL_X, COLOR_WALL_Y, COLOR_WALL_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(7.149944f, 2.0f, 9.0f); 
		glScalef(2.0, 12.0, 0.5);  
		glColor3f(COLOR_WALL_X, COLOR_WALL_Y, COLOR_WALL_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	//Fim bordas da porta

	//Complemento cima porta

	glPushMatrix();
		glTranslatef(5.0f, 4.0f, 9.0f); 
		glScalef(7.2f, 4.0, 0.5);  
		glColor3f(COLOR_WALL_X, COLOR_WALL_Y, COLOR_WALL_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	//Fim Complemento

	//Circulo do meio

	glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
			float centro_x = 5.0919950f;
			float centro_y = 10.0f;
			float raio = 1.0;

			glVertex3d(centro_x, centro_y, 5.5f);

			for(int i = 0; i <= 360; i++){
				double theta = (2 * i * PI) / 360.0;

				double x = centro_x + raio * cos(theta);
				double y = centro_y + raio * sin(theta);
				glColor3f(0.2, 0.3, 0.6);
				glVertex3d(x, y, 5.5f);
			}
		glEnd();
	glPopMatrix();

	//Fim circulo do meio

	//Janelas do meio cima

	glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
			centro_x = 4.475443f;
			centro_y = 12.5;
			raio = 0.4;

			glVertex3d(centro_x, centro_y, 5.5f);

			for(int i = 0; i <= 360; i++){
				double theta = (i * PI) / 360.0;

				double x = centro_x + raio * cos(theta);
				double y = centro_y + raio * sin(theta);

				glVertex3d(x, y, 5.5f);
			}
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
			centro_x = 5.725435f;
			centro_y = 12.5;
			raio = 0.4;

			glVertex3d(centro_x, centro_y, 5.5f);

			for(int i = 0; i <= 360; i++){
				double theta = (i * PI) / 360.0;

				double x = centro_x + raio * cos(theta);
				double y = centro_y + raio * sin(theta);

				glVertex3d(x, y, 5.5f);
			}
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(4.429941f, 12.0f, 5.5f); 
		glColor3f(COLOR_DOOR_X, COLOR_DOOR_Y, COLOR_DOOR_Z);
		glScalef(1.7, 2.0, 0.5);
		glutSolidCube(0.5);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(5.719941f, 12.0f, 5.5f); 
		glColor3f(COLOR_DOOR_X, COLOR_DOOR_Y, COLOR_DOOR_Z);
		glScalef(1.7, 2.0, 0.5);
		glutSolidCube(0.5);
	glPopMatrix();

	//Fim Janelas do meio cima

	//Semicirculo da porta
	glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
			centro_x = 4.919950f;
			centro_y = 2.5;
			raio = 1.7;

			glVertex3d(centro_x, centro_y, 9.5f);

			for(int i = 0; i <= 180; i++){
				double theta = (i * PI) / 360.0;

				double x = centro_x + raio * cos(theta);
				double y = centro_y + raio * sin(theta);

				glVertex3d(x, y, 9.5f);
			}
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
			centro_x = 4.919950f;
			centro_y = 2.5;
			raio = 1.7;

			glVertex3d(centro_x, centro_y, 9.5f);

			for(int i = 180; i <= 360; i++){
				double theta = (i * PI) / 360.0;

				double x = centro_x + raio * cos(theta);
				double y = centro_y + raio * sin(theta);

				glVertex3d(x, y, 9.5f);
			}
		glEnd();
	glPopMatrix();

	//Porta

	glPushMatrix();
		glTranslatef(3.069969f, 1.0f, 8.7f); 
		glRotatef(angle_porta, 0, 1, 0); 
		glTranslatef(0.85f, 0.0f, -0.05f);
		glColor3f(COLOR_DOOR_X, COLOR_DOOR_Y, COLOR_DOOR_Z);
		glScalef(4.3, 8.0, 0.5);  
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(6.869998f, 1.0f, 8.7f); 
		glRotatef(-angle_porta, 0, 1, 0);  
		glTranslatef(-0.85f, 0.0f, -0.05f);
		glColor3f(COLOR_DOOR_X, COLOR_DOOR_Y, COLOR_DOOR_Z);
		glScalef(4.3, 8.0, 0.5);  
		glutSolidCube(0.5);
    glPopMatrix();

	//Fim porta

	glPushMatrix();
		glTranslatef(2.26f, 2.0f, 5.0f); 
		glScalef(0.5, 12.0, 15.0);  
		glColor3f(COLOR_WALL_X, COLOR_WALL_Y, COLOR_WALL_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(7.869974f, 2.0f, 5.0f); 
		glScalef(0.5, 12.0, 15.0);  
		glColor3f(COLOR_WALL_X, COLOR_WALL_Y, COLOR_WALL_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(10.0f, 2.0f, 1.0f); 
		glScalef(10.0, 12.0, 1.0);  
		glColor3f(COLOR_WALL_X, COLOR_WALL_Y, COLOR_WALL_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(12.5f, 2.0f, -30.0f); 
		glScalef(0.5, 12.0, -125.0);  
		glColor3f(COLOR_WALL_X, COLOR_WALL_Y, COLOR_WALL_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(-2.6f, 2.0f, -30.0f); 
		glScalef(0.5, 12.0, -125.0);  
		glColor3f(COLOR_WALL_X, COLOR_WALL_Y, COLOR_WALL_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(5.0f, 2.019999f, -61.588894f); 
		glScalef(30.0, 12.0, 1.0f); 
		glColor3f(COLOR_WALL_X, COLOR_WALL_Y, COLOR_WALL_Z);
		glutSolidCube(0.5);
    glPopMatrix();
}

void drawRoof(){
	glPushMatrix();
		glTranslatef(-0.700000f, 6.100002f, 1.0f); 
		glRotatef(45.0f, 0, 0, 1);
		glScalef(100.199356f, 2.0f, 100.0f);
		glColor3f(COLOR_WALL_X, COLOR_WALL_X, COLOR_WALL_X);
		glutSolidCube(0.05);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(10.600002f, 6.100002f, 1.0f); 
		glRotatef(-45.0f, 0, 0, 1);
		glScalef(100.199356f, 2.0f, 100.0f);
		glColor3f(COLOR_WALL_X, COLOR_WALL_X, COLOR_WALL_X);
		glutSolidCube(0.05);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(3.599999f, 5.400001f, 7.5f); 
		glRotatef(20.0f, 0, 0, 1);
		glScalef(60.199356f, 2.0f, 70.0f);
		glColor3f(COLOR_WALL_X, COLOR_WALL_X, COLOR_WALL_X);
		glutSolidCube(0.05);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(6.200002f, 5.400001f, 7.5f); 
		glRotatef(-20.0f, 0, 0, 1);
		glScalef(60.199356f, 2.0f, 70.0f);
		glColor3f(COLOR_WALL_X, COLOR_WALL_X, COLOR_WALL_X);
		glutSolidCube(0.05);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(2.100001f, 13.200005, 1.700001f); 
		glRotatef(45.0f, 0, 0, 1);
		glScalef(45.9f, 2.0f, 70.0f);
		glColor3f(COLOR_WALL_X, COLOR_WALL_X, COLOR_WALL_X);
		glutSolidCube(0.05);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(2.100001f, 13.200005, 1.700001f); 
		glRotatef(45.0f, 0, 0, 1);
		glScalef(45.9f, 2.0f, 70.0f);
		glColor3f(COLOR_WALL_X, COLOR_WALL_X, COLOR_WALL_X);
		glutSolidCube(0.05);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(7.900000f, 13.200005, 1.700001f); 
		glRotatef(-45.0f, 0, 0, 1);
		glScalef(45.9f, 2.0f, 70.0f);
		glColor3f(COLOR_WALL_X, COLOR_WALL_X, COLOR_WALL_X);
		glutSolidCube(0.05);
    glPopMatrix();

}

void drawFloor(){
	glPushMatrix();
		glTranslatef(-5.0f, -1.5f, -4.0f); 
		glScalef(300.0f, 0.0f, 1000.0f);
		glColor3f(COLOR_WALL_X, COLOR_WALL_X, COLOR_WALL_X);
		glutSolidCube(0.5);
    glPopMatrix();
}

void drawRoofTemple(){
	glPushMatrix();
		glTranslatef(5.0f, 5.0f, -30.0f); 
		glScalef(30.0f, 0.0f, -125.0f);
		glColor3f(COLOR_WALL_X, COLOR_WALL_X, COLOR_WALL_X);
		glutSolidCube(0.5);
    glPopMatrix();
}

void drawAirConditioning(float x, float z){
	glPushMatrix();
		glTranslatef(x, 3.5f, z); 
		glScalef(1.5f, 1.0f, 7.0f);
		glColor3f(COLOR_WALL_X, COLOR_WALL_X, COLOR_WALL_X);
		glutSolidCube(0.5);
    glPopMatrix();
}

void drawLamp(float x, float z, float angle){
	glPushMatrix();
		glTranslatef(x, 5.0f, z); 
		glRotatef(angle, 0, 1, 0);
		glScalef(3.0f, 0.5f, 1.0f);
		glColor3f(COLOR_WALL_X, COLOR_WALL_X, COLOR_WALL_X);
		glutSolidCube(0.5);
    glPopMatrix();
}

void drawChair(int x, int z){
	glPushMatrix();
		glTranslatef(x, -0.5f, z); 
		glScalef(0.25f, 2.5f, 1.5f);
		glColor3f(COLOR_WALL_X, COLOR_WALL_X, COLOR_WALL_X);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(x - 0.14, -1.0f, z - 1.4f); 
		glScalef(0.25f, 1.25f, 2.0f);
		glColor3f(COLOR_WALL_X, COLOR_WALL_X, COLOR_WALL_X);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(x + 1.837f, -0.5f, z); 
		glScalef(0.25f, 2.5f, 1.5f);
		glColor3f(COLOR_WALL_X, COLOR_WALL_X, COLOR_WALL_X);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(x - 0.33 + 2.0f, -1.0f, z - 1.4f); 
		glScalef(0.25f, 1.25f, 2.0f);
		glColor3f(COLOR_WALL_X, COLOR_WALL_X, COLOR_WALL_X);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(x + 0.9f, -0.719998f, z - 1.4f); 
		glScalef(4.0f, 0.1f, 2.0f);
		glColor3f(COLOR_WALL_X, COLOR_WALL_X, COLOR_WALL_X);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(x + 0.9f, -0.319998f, z); 
		glRotatef(-45.0f, 1, 0, 0);
		glScalef(4.0f, 0.1f, 2.0f);
		glColor3f(COLOR_WALL_X, COLOR_WALL_X, COLOR_WALL_X);
		glutSolidCube(0.5);
    glPopMatrix();
}

void drawSoundStereo(float x, float z, float angle){
	glPushMatrix();
		glTranslatef(x + 0.7f, 2.5f, z);
		glRotatef(angle, 0, 0, 1);
		glScalef(0.4f, 1.0f, 1.0f);
		glColor3f(COLOR_WALL_X, COLOR_WALL_X, COLOR_WALL_X);
		glutSolidCube(0.5);
    glPopMatrix();
}

void drawMainStage(float x_centro, float y_centro, float raio){
	GLUquadricObj *p = gluNewQuadric();

	glPushMatrix();
		glTranslatef(5.0f, -1.0f, -59.279907f);
		glRotatef(-90.0f, -1.0, 0, 0);
		gluCylinder(p, 4.0f, 4.0f, 1.0f, 100, 100);
	glPopMatrix();

	GLUquadricObj *s = gluNewQuadric();
	gluQuadricDrawStyle(s, GLU_FILL);
	glPushMatrix();
		glTranslatef(5.0f, 0.0f, -59.279907f);
		glRotatef(-90.0f, -1.0, 0, 0);
		gluCylinder(s, 3.0f, 3.0f, 1.0f, 100, 100);
	glPopMatrix();
}

void drawFrontWindows(){

	glBegin(GL_TRIANGLE_FAN);
		float centro_x = -0.445;
    	float centro_y = 3.0;
        float raio = 1.0;

        glVertex3d(centro_x, centro_y, 1.5f);

        for(int i = 0; i <= 360; i++){
            double theta = (i * PI) / 360.0;

            double x = centro_x + raio * cos(theta);
            double y = centro_y + raio * sin(theta);

            glVertex3d(x, y, 1.5f);
		}
	glEnd();

	glPushMatrix();
		glTranslatef(-0.5f, 1.5f, 1.3f); 
		glScalef(4.0, 6.0, 1.0);  
		glColor3f(COLOR_DOOR_X, COLOR_DOOR_Y, COLOR_DOOR_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(10.8f, 1.5f, 1.3f); 
		glScalef(4.0, 6.0, 1.0);  
		glColor3f(COLOR_DOOR_X, COLOR_DOOR_Y, COLOR_DOOR_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	glBegin(GL_TRIANGLE_FAN);
		centro_x = 10.765;
    	centro_y = 3.0;
        raio = 1.0;

        glVertex3d(centro_x, centro_y, 1.5f);

        for(int i = 0; i <= 360; i++){
            double theta = (i * PI) / 360.0;

            double x = centro_x + raio * cos(theta);
            double y = centro_y + raio * sin(theta);

            glVertex3d(x, y, 1.5f);
		}
	glEnd();

}	

void display(void){

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);     
	
	glLoadIdentity();

	gluLookAt(x, y, z, x + lx, y, z + lz, 0.0f, 1.0f, 0.0f);

	if(!DEBUG)
		printf("%f %f %f %f %f %f\n", x, y, z, lx, lz);

	drawTemple();
	drawRoof();
	drawFloor();
	drawRoofTemple();

	drawAirConditioning(-2.0f, -10.0f);
	drawAirConditioning(-2.0f, -20.0f);
	drawAirConditioning(-2.0f, -30.0f);

	drawAirConditioning(12.0f, -10.0f);
	drawAirConditioning(12.0f, -20.0f);
	drawAirConditioning(12.0f, -30.0f);

	drawLamp(3.0f, -10.0f, 45.0f);
	drawLamp(3.0f, -15.0f, 45.0f);
	drawLamp(3.0f, -20.0f, 45.0f);
	drawLamp(3.0f, -25.0f, 45.0f);

	drawLamp(7.0f, -10.0f, -45.0f);
	drawLamp(7.0f, -15.0f, -45.0f);
	drawLamp(7.0f, -20.0f, -45.0f);
	drawLamp(7.0f, -25.0f, -45.0f);

	drawLamp(5.0f, -20.0f, 0.0f);
	drawLamp(5.0f, -25.0f, 0.0f);

	drawChair(0.5f, -5.0f);
	drawChair(0.5f, -10.0f);
	drawChair(0.5f, -20.0f);
	drawChair(0.5f, -30.0f);
	drawChair(0.5f, -15.0f);
	drawChair(0.5f, -25.0f);
	drawChair(0.5f, -35.0f);

	drawChair(9.5f, -5.0f);
	drawChair(9.5f, -10.0f);
	drawChair(9.5f, -20.0f);
	drawChair(9.5f, -30.0f);
	drawChair(9.5f, -15.0f);
	drawChair(9.5f, -25.0f);
	drawChair(9.5f, -35.0f);

	drawSoundStereo(-2.0f, -12.0f, 45.0);
	drawSoundStereo(-2.0f, -22.0f, 45.0);
	drawSoundStereo(-2.0f, -32.0f, 45.0);

	drawSoundStereo(12.0f, -12.0f, -45.0);
	drawSoundStereo(12.0f, -22.0f, -45.0);
	drawSoundStereo(12.0f, -32.0f, -45.0);

	drawMainStage(7.0f, -30.0f, 2.0f);

	drawFrontWindows();

	glFlush();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch(key){
        case 'p':
			if(angle_porta >= 90.0f) 
				angle_porta = 0;
			else
				angle_porta += 10.0f;
			break;
    }
}

void processSpecialKeys(int key, int xx, int yy){
	float fraction = 0.5f;
	float fraction_2 = 0.1f;

	switch (key){
		case GLUT_KEY_LEFT :
			if(DEBUG){
				debugx -= 0.01;
			}else{
				angle -= 0.05f;
				lx = sin(angle);
				lz = -cos(angle);
			}
		break;
		case GLUT_KEY_RIGHT :
			if(DEBUG){
				debugx += 0.1;
			}else{
				angle += 0.05f;
				lx = sin(angle);
				lz = -cos(angle);
			}
		break;
		case GLUT_KEY_UP :
			x += lx * fraction;
			z += lz * fraction;
		break;
		case GLUT_KEY_DOWN :
			x -= lx * fraction;
			z -= lz * fraction;
		break;
		case GLUT_KEY_PAGE_UP:
			y += y * fraction_2;
		break;
		case GLUT_KEY_PAGE_DOWN:
			y -= y * fraction_2;
		break;
	}

	printf("%f\n", debugx);
}

	
void init() {
  glClearColor(0.7, 1.0, 1.0, 0.0);

  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);

  glEnable(GL_COLOR_MATERIAL);

  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);
  
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
 
  glEnable(GL_TEXTURE_2D);
 
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, WIDTH, 0, HEIGHT, -1, 1);
}

void reshape(GLsizei width, GLsizei height)
{
  if (height == 0) {
      height = 1;
  }

  glViewport(0, 0, width, height);

  float ratio = width * 1.0 / height;

  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();

  gluPerspective(45.0f, ratio, 0.1f, 100.0f);

  glMatrixMode(GL_MODELVIEW);

}

int main(int argc,char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH| GLUT_DOUBLE);
  glutInitWindowSize(WIDTH,HEIGHT);
  glutInitWindowPosition(10, 10);

  if(!glutCreateWindow("Igreja")) {
    fprintf(stderr,"Error opening a window.\n");
    exit(-1);
  }

  init();

  glutKeyboardFunc(keyboard);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(display);
  glutSpecialFunc(processSpecialKeys);

  glutMainLoop();

  return 0;
}