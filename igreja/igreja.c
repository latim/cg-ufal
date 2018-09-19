#include <stdio.h>
#ifdef __APPLE__
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif
#include <math.h>
#include <unistd.h>

#define COLOR_WALL_X 0.4
#define COLOR_WALL_Y 0.4
#define COLOR_WALL_Z 0.1

#define COLOR_DOOR_X 0.4
#define COLOR_DOOR_Y 0.3
#define COLOR_DOOR_Z 0

#define COLOR_CIRCLE_X 0.4
#define COLOR_CIRCLE_Y 0.2
#define COLOR_CIRCLE_Z 0

#define COLOR_CHAIR_X 0.6
#define COLOR_CHAIR_Y 0.4
#define COLOR_CHAIR_Z 0.0

#define COLOR_AIR_X 1
#define COLOR_AIR_Y 1
#define COLOR_AIR_Z 1

#define COLOR_LAMP_X 1
#define COLOR_LAMP_Y 1
#define COLOR_LAMP_Z 1

#define COLOR_SIDE_X 1
#define COLOR_SIDE_Y 1
#define COLOR_SIDE_Z 1

#define COLOR_ROOF_X 1
#define COLOR_ROOF_Y 1
#define COLOR_ROOF_Z 0.8

#define COLOR_SOUND_X 1
#define COLOR_SOUND_Y 1
#define COLOR_SOUND_Z 1

#define COLOR_FLOOR_X 1
#define COLOR_FLOOR_Y 1
#define COLOR_FLOOR_Z 0

#define COLOR_YELLOW_WALL_X 1
#define COLOR_YELLOW_WALL_Y 1
#define COLOR_YELLOW_WALL_Z 0.2

#define COLOR_BLACK 0

#define DEBUG 1

#define PI 3.14

GLint WIDTH = 700;
GLint HEIGHT = 700;

//float lx = 0.0f, lz = -1.0f;
//float x = 5.0f, z = 20.0f, y = 1.0f;

float lx = 0.0f, lz = -1.0f, ly;
//float x = 4.609134f, z = 46.560791f, y = 1.0f;
float x = 9.292539f, z = -9.354383f, y = 1.000000f;

float angle = 0.0f;

float angle_porta = 0;

int mouseX;
int mouseY;

float angleY = 0;

float debugx =  1.7f;

int controle = 0;

void cameraViewUpdate(){
    lx = sin(angle);
   	ly = sin(angleY);
    lz = -cos(angle);
}

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
			glColor3f(COLOR_WALL_X, COLOR_WALL_Y, COLOR_WALL_Z);
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
		glColor3f(COLOR_WALL_X, COLOR_WALL_Y, COLOR_WALL_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(5.0f, 8.7f, 1.2f);
		glScalef(15.0, 15.0, 10.0);  
		glColor3f(COLOR_WALL_X, COLOR_WALL_Y, COLOR_WALL_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	//Bordas da porta

	glPushMatrix();
		glTranslatef(2.839999f, 2.0f, 9.0f); 
		glScalef(2.0, 12.0, 0.5);  
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
				glColor3f(COLOR_CIRCLE_X, COLOR_CIRCLE_Y, COLOR_CIRCLE_Z);
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
			centro_x = 4.959950f;
			centro_y = 2.5;
			raio = 1.6;

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
			centro_x = 4.959950f;
			centro_y = 2.5;
			raio = 1.6;

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
		glColor3f(COLOR_ROOF_X, COLOR_ROOF_Y, COLOR_ROOF_Z);
		glutSolidCube(0.5);
    glPopMatrix();
}

void drawAirConditioning(float x, float z){
	glPushMatrix();
		glTranslatef(x, 4.5f, z); 
		glScalef(1.5f, 1.0f, 7.0f);
		glColor3f(COLOR_AIR_X, COLOR_AIR_X, COLOR_AIR_X);
		glutSolidCube(0.5);
    glPopMatrix();
}

void drawLamp(float x, float z, float angle){
	glPushMatrix();
		glTranslatef(x, 5.0f, z); 
		glRotatef(angle, 0, 1, 0);
		glScalef(3.0f, 0.5f, 1.0f);
		glColor3f(COLOR_LAMP_X, COLOR_LAMP_X, COLOR_LAMP_X);
		glutSolidCube(0.5);
    glPopMatrix();
}

void drawChair(int x, int z){
	glPushMatrix();
		glTranslatef(x, -0.5f, z); 
		glScalef(0.25f, 2.5f, 1.5f);
		glColor3f(COLOR_CHAIR_X, COLOR_CHAIR_Y, COLOR_CHAIR_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(x - 0.040001, -1.0f, z + -0.839999); 
		glScalef(0.25f, 1.25f, 2.0f);
		glColor3f(COLOR_CHAIR_X, COLOR_CHAIR_Y, COLOR_CHAIR_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(x + 1.837f, -0.5f, z); 
		glScalef(0.25f, 2.5f, 1.5f);
		glColor3f(COLOR_CHAIR_X, COLOR_CHAIR_Y, COLOR_CHAIR_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(x - 0.33 + 2.180000f, -1.0f, z + -0.839999); 
		glScalef(0.25f, 1.25f, 2.0f);
		glColor3f(COLOR_CHAIR_X, COLOR_CHAIR_Y, COLOR_CHAIR_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(x + 0.900001, -0.719998f, z - 0.810001f); 
		glScalef(4.0f, 0.1f, 2.0f);
		glColor3f(COLOR_CHAIR_X, COLOR_CHAIR_Y, COLOR_CHAIR_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(x + 0.9f, -0.319998f, z); 
		glRotatef(-45.0f, 1, 0, 0);
		glScalef(4.0f, 0.1f, 2.0f);
		glColor3f(COLOR_CHAIR_X, COLOR_CHAIR_Y, COLOR_CHAIR_Z);
		glutSolidCube(0.5);
    glPopMatrix();
}

void drawSoundStereo(float x, float z, float angle){
	glPushMatrix();
		glTranslatef(x + 0.7f, 2.5f, z);
		glRotatef(angle, 0, 0, 1);
		glScalef(0.4f, 1.0f, 1.0f);
		glColor3f(COLOR_SOUND_X, COLOR_SOUND_X, COLOR_SOUND_X);
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

void drawTriangle(){
	glColor3f(COLOR_WALL_X, COLOR_WALL_Y, COLOR_WALL_Z);
	glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
			glVertex3f(-1.700000f, 5.100002f, 1.0f);
			glVertex3f(3.0f, 5.100002f, 1.0f);
			glVertex3f(1.0f, 8.100002f, 1.0f);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
			glVertex3f(8.700000f, 4.100002f, 1.0f);
			glVertex3f(8.700000f, 8.100002f, 1.0f);
			glVertex3f(12.0f, 4.100002f, 1.0f);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
			glVertex3f(1.20001f, 12.200005, 2.700001f);
			glVertex3f(3.0f, 12.200005, 2.700001f);
			glVertex3f(3.0f, 14.100002f, 2.700001f);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
			glVertex3f(7.000000f, 12.200005, 2.700001f);
			glVertex3f(7.00000f, 14.100002f, 2.700001f);
			glVertex3f(8.5f, 12.200005, 3.700001f);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
			glVertex3f(2.839999f, 5.0f, 9.0f);
			glVertex3f(7.00000f, 5.0f, 9.0f);
			glVertex3f(4.9f, 5.900005, 9.0f);
		glEnd();
	glPopMatrix();
}

void drawFrontWindows(){

	glBegin(GL_TRIANGLE_FAN);
		float centro_x = -0.50;
    	float centro_y = 3.0;
        float raio = 1.0;
		glColor3f(COLOR_DOOR_X, COLOR_DOOR_Y, COLOR_DOOR_Z);
        glVertex3d(centro_x, centro_y, 1.5f);

        for(int i = 0; i <= 360; i++){
            double theta = (i * PI) / 360.0;

            double x = centro_x + raio * cos(theta);
            double y = centro_y + raio * sin(theta);
			
            glVertex3d(x, y, 1.5f);
		}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
		centro_x = -0.50;
    	centro_y = 3.0;
        raio = 1.0;
		glColor3f(COLOR_DOOR_X, COLOR_DOOR_Y, COLOR_DOOR_Z);
        glVertex3d(centro_x, centro_y, 0.680000);

        for(int i = 0; i <= 360; i++){
            double theta = (i * PI) / 360.0;

            double x = centro_x + raio * cos(theta);
            double y = centro_y + raio * sin(theta);
			
            glVertex3d(x, y, 0.680000);
		}
	glEnd();

	glPushMatrix();
		glTranslatef(-0.5f, 1.5f, 1.3f); 
		glScalef(4.0, 6.0, 1.0);  
		glColor3f(COLOR_DOOR_X, COLOR_DOOR_Y, COLOR_DOOR_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.5f, 1.5f, 0.9f); 
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

	glPushMatrix();
		glTranslatef(10.8f, 1.5f, 0.9f); 
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
			glColor3f(COLOR_DOOR_X, COLOR_DOOR_Y, COLOR_DOOR_Z);
            glVertex3d(x, y, 1.5f);
		}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
		centro_x = 10.765;
    	centro_y = 3.0;
        raio = 1.0;

        glVertex3d(centro_x, centro_y, 0.680000);

        for(int i = 0; i <= 360; i++){
            double theta = (i * PI) / 360.0;

            double x = centro_x + raio * cos(theta);
            double y = centro_y + raio * sin(theta);
			glColor3f(COLOR_DOOR_X, COLOR_DOOR_Y, COLOR_DOOR_Z);
            glVertex3d(x, y, 0.680000);
		}
	glEnd();

}	

void drawSideWindows(int x, int z, int offset_y){
	glColor3f(COLOR_SIDE_X, COLOR_SIDE_Y, COLOR_SIDE_Z);

	glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
			float centro_x = z;
			float centro_y = 3.0f;
			if(offset_y > 0){
				centro_y = 3.13f;
			}
			float raio = 0.6;

			glVertex3d(x, centro_y, centro_x);

			for(int i = 0; i <= 180; i++){
				double theta = (2 * i * PI) / 360.0;

				double _x = centro_x + raio * cos(theta);
				double y = centro_y + raio * sin(theta);

				glVertex3d(x, y, _x);
			}
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glBegin(GL_TRIANGLE_FAN);
			centro_x = z;
			centro_y = 3.0f;
			if(offset_y > 0){
				centro_y = 3.13f;
			}
			raio = 0.6;

			glVertex3d(x + 0.8f, centro_y, centro_x);

			for(int i = 0; i <= 180; i++){
				double theta = (2 * i * PI) / 360.0;

				double _x = centro_x + raio * cos(theta);
				double y = centro_y + raio * sin(theta);

				glVertex3d(x + 0.8f, y, _x);
			}
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(x, 1.5f, z); 
		glScalef(0.0f, 6.0f + offset_y, 2.5f);
		glColor3f(COLOR_LAMP_X, COLOR_LAMP_X, COLOR_LAMP_X);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(x + 0.8f, 1.5f, z); 
		glScalef(0.0f, 6.0f + offset_y, 2.5f);
		glColor3f(COLOR_LAMP_X, COLOR_LAMP_X, COLOR_LAMP_X);
		glutSolidCube(0.5);
    glPopMatrix();
}

void drawInsideFirstFloor(){
	glPushMatrix();
		glTranslatef(11.379995f, 0.6f, -57.699547f); 
		glScalef(4.0f, 7.0f, 2.0f);
		glColor3f(COLOR_FLOOR_X, COLOR_FLOOR_Y, COLOR_FLOOR_Z);
		glutSolidCube(0.5);
    glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-0.169999f, 0.6f, -58.899547f); 
		glScalef(1.0f, 7.0f, 7.5f);
		glColor3f(COLOR_FLOOR_X, COLOR_FLOOR_Y, COLOR_FLOOR_Z);
		glutSolidCube(0.5);
    glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-1.429996f, 0.6f, -57.699547f); 
		glScalef(4.0f, 7.0f, 2.0f);
		glColor3f(COLOR_FLOOR_X, COLOR_FLOOR_Y, COLOR_FLOOR_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(10.3f, 0.6f, -58.899547f); 
		glScalef(0.5f, 7.0f, 7.5f);
		glColor3f(COLOR_FLOOR_X, COLOR_FLOOR_Y, COLOR_FLOOR_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(10.3f, 8.2f, -58.899547f); 
		glScalef(0.5f, 1.0f, 0.5f);
		glColor3f(COLOR_FLOOR_X, COLOR_FLOOR_Y, COLOR_FLOOR_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	//parte de cima direita

	glPushMatrix();
		glTranslatef(10.3f, 2.59f, -57.479237f); 
		glScalef(0.5f, 1.0f, 0.5f);
		glColor3f(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(10.3f, 2.59f, -58.479237f); 
		glScalef(0.5f, 1.0f, 0.5f);
		glColor3f(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(10.3f, 2.59f, -59.479237f); 
		glScalef(0.5f, 1.0f, 0.5f);
		glColor3f(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(10.3f, 2.59f, -59.479237f); 
		glScalef(0.5f, 1.0f, 0.5f);
		glColor3f(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(12.290002f, 2.59f, -57.479237f); 
		glScalef(0.5f, 1.0f, 0.5f);
		glColor3f(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(11.290002f, 2.59f, -57.479237f); 
		glScalef(0.5f, 1.0f, 0.5f);
		glColor3f(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
		glutSolidCube(0.5);
    glPopMatrix();

	//parte de cima

	glPushMatrix();
		glTranslatef(10.3000f, 2.8f, -58.479237f); 
		glScalef(0.5f, 0.2f, 3.5f);
		glColor3f(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(11.0000f, 2.7f, -57.258945); 
		glScalef(3.5f, 0.2f, 0.5f);
		glColor3f(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
		glutSolidCube(0.5);
    glPopMatrix();

	//fim parte de cima

	//fim parte direita

	//parte de cima esquerda

	glPushMatrix();
		glTranslatef(-0.2f, 2.59f, -57.479237f); 
		glScalef(0.5f, 1.0f, 0.5f);
		glColor3f(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.2f, 2.59f, -58.479237f); 
		glScalef(0.5f, 1.0f, 0.5f);
		glColor3f(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.2f, 2.59f, -59.479237f); 
		glScalef(0.5f, 1.0f, 0.5f);
		glColor3f(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.6f, 2.59f, -59.479237f); 
		glScalef(0.5f, 1.0f, 0.5f);
		glColor3f(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.9f, 2.59f, -57.479237f); 
		glScalef(0.5f, 1.0f, 0.5f);
		glColor3f(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.6f, 2.59f, -57.479237f); 
		glScalef(0.5f, 1.0f, 0.5f);
		glColor3f(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(-2.4f, 2.59f, -57.479237f); 
		glScalef(0.5f, 1.0f, 0.5f);
		glColor3f(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
		glutSolidCube(0.5);
    glPopMatrix();

	//parte de cima

	glPushMatrix();
		glTranslatef(-0.2f, 2.8f, -58.479237f); 
		glScalef(0.5f, 0.2f, 3.5f);
		glColor3f(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.2f, 2.7f, -57.258945); 
		glScalef(4.5f, 0.2f, 0.5f);
		glColor3f(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
		glutSolidCube(0.5);
    glPopMatrix();

	//fim parte de cima

	//fim parte esquerda
}

void drawBehindBuilding(){
	glPushMatrix();
		glTranslatef(-3.0f, 2.019999f, -66.588894f); 
		glScalef(1.0, 24.0, 14.0f); 
		glColor3f(COLOR_WALL_X, COLOR_WALL_Y, COLOR_WALL_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(14.0f, 2.019999f, -66.588894f); 
		glScalef(1.0, 24.0, 14.0f); 
		glColor3f(COLOR_WALL_X, COLOR_WALL_Y, COLOR_WALL_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(5.5f, 2.019999f, -62.588894f); 
		glScalef(33.0, 24.0, 1.0f); 
		glColor3f(COLOR_WALL_X, COLOR_WALL_Y, COLOR_WALL_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(5.5f, 2.019999f, -69.588894f); 
		glScalef(33.0, 24.0, 1.0f); 
		glColor3f(COLOR_WALL_X, COLOR_WALL_Y, COLOR_WALL_Z);
		glutSolidCube(0.5);
    glPopMatrix();

	glPushMatrix();
		glTranslatef(5.5f, 8.019999f, -65.588894f); 
		glScalef(33.0, 1.0, 16.0f); 
		glColor3f(COLOR_WALL_X, COLOR_WALL_Y, COLOR_WALL_Z);
		glutSolidCube(0.5);
    glPopMatrix();
}

void drawYellowWall(){
	glPushMatrix();
		glTranslatef(5.5f, 1.619999f, -60.888894f); 
		glScalef(29.0, 13.0, 1.0f); 
		glColor3f(COLOR_YELLOW_WALL_X, COLOR_YELLOW_WALL_Y, COLOR_YELLOW_WALL_Z);
		glutSolidCube(0.5);
    glPopMatrix();
}

void drawTableWithCross(){
	
}

void display(void){

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);     
	
	glLoadIdentity();

	cameraViewUpdate();
	gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);

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

	drawSoundStereo(10.0f, -12.0f, -45.0);
	drawSoundStereo(10.0f, -22.0f, -45.0);
	drawSoundStereo(10.0f, -32.0f, -45.0);

	drawMainStage(7.0f, -30.0f, 2.0f);

	drawTriangle();
	drawFrontWindows();

	drawSideWindows(-3.01f, -3.0f, 1.0f);

	drawSideWindows(-3.01f, -7.0f, 0.0f);
	drawSideWindows(-3.01f, -9.5f, 0.0f);

	drawSideWindows(-3.01f, -13.5f, 0.0f);
	drawSideWindows(-3.01f, -15.5f, 0.0f);

	drawSideWindows(-3.01f, -19.5f, 0.0f);
	drawSideWindows(-3.01f, -21.5f, 0.0f);

	drawSideWindows(-3.01f, -25.5f, 0.0f);
	drawSideWindows(-3.01f, -27.5f, 1.0f);

	drawSideWindows(-3.01f, -31.5f, 0.0f);
	drawSideWindows(-3.01f, -34.5f, 0.0f);

	drawSideWindows(-3.01f, -38.5f, 0.0f);
	drawSideWindows(-3.01f, -40.5f, 0.0f);

	drawSideWindows(-3.01f, -44.5f, 0.0f);
	drawSideWindows(-3.01f, -46.5f, 0.0f);

	drawSideWindows(-3.01f, -3.0f, 1.0f);

	int pos_side_x = 12.0f;

	drawSideWindows(pos_side_x, -3.0f, 1.0f);

	drawSideWindows(pos_side_x, -7.0f, 0.0f);
	drawSideWindows(pos_side_x, -9.5f, 0.0f);

	drawSideWindows(pos_side_x, -13.5f, 0.0f);
	drawSideWindows(pos_side_x, -15.5f, 0.0f);

	drawSideWindows(pos_side_x, -19.5f, 0.0f);
	drawSideWindows(pos_side_x, -21.5f, 0.0f);

	drawSideWindows(pos_side_x, -25.5f, 0.0f);
	drawSideWindows(pos_side_x, -27.5f, 1.0f);

	drawSideWindows(pos_side_x, -31.5f, 0.0f);
	drawSideWindows(pos_side_x, -34.5f, 0.0f);

	drawSideWindows(pos_side_x, -38.5f, 0.0f);
	drawSideWindows(pos_side_x, -40.5f, 0.0f);

	drawSideWindows(pos_side_x, -44.5f, 0.0f);
	drawSideWindows(pos_side_x, -46.5f, 0.0f);

	drawInsideFirstFloor();

	if(!controle){
		if(access("/Users/dayvsonsales/cg-ufal-2018/igreja/portao.txt", F_OK) != -1) {
			angle_porta = 90.0f;
		}else{
			angle_porta = 0.0f;
		}
	}
	
	drawBehindBuilding();
	drawYellowWall();

	glFlush();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int _x, int _y) {
    switch(key){
		case 'i': case 'I':
			y += 1;
			glutPostRedisplay();
		break;
		case 'k': case 'K':
			y -= 1;
			glutPostRedisplay();
		break;
		case 'z': case 'Z':
			x = 4.609134f;
			z = 46.560791f; 
			y = 20.0f;
			glutPostRedisplay();
		break;
		case 'g': case 'G':
			controle = !controle;
		break;
        case 'p': case 'P':
			if(angle_porta >= 90.0f) 
				angle_porta = 0;
			else
				angle_porta += 10.0f;
		break;
    }
}

void processSpecialKeys(int key, int xx, int yy){
	float fraction = 0.5f;
	float fraction_2 = 0.3f;

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

void mousePassive(int x, int y){
    mouseX = x;
    mouseY = y;
}

void mouseMotion(int x, int y){
    float speed = 110.0f;

    angle += (mouseX - x) / speed;
    angleY -= (mouseY - y) / speed;

    mousePassive(x, y);
    glutPostRedisplay();
}

void mouseFunc(int button, int state, int _x, int _y){
    float fracao = 0.4;
	
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        x += lx * fracao;
        z += lz * fracao;
    } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
        x -= lx * fracao;
        z -= lz * fracao;
    }
}

void timer(){
	glutPostRedisplay();
	glutTimerFunc(100, timer, 0);
}

int main(int argc,char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH| GLUT_DOUBLE);
  glutInitWindowSize(WIDTH,HEIGHT);
  glutInitWindowPosition(10, 10);

  glutCreateWindow("Igreja");

  init();

  glutMotionFunc(mouseMotion);
  glutPassiveMotionFunc(mousePassive);
  glutMouseFunc(mouseFunc);
  glutKeyboardFunc(keyboard);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(display);
  glutSpecialFunc(processSpecialKeys);

  timer();

  glutMainLoop();

  return 0;
}