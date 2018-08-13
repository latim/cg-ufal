
#include <GLUT/glut.h>
#include <stdlib.h>
#include <stdio.h>

static GLubyte smiley[] = /* 16x16 smiley face */
  {
    0x03, 0xc0, 0, 0, /*       ****       */
    0x0f, 0xf0, 0, 0, /*     ********     */
    0x1e, 0x78, 0, 0, /*    ****  ****    */
    0x39, 0x9c, 0, 0, /*   ***  **  ***   */
    0x77, 0xee, 0, 0, /*  *** ****** ***  */
    0x6f, 0xf6, 0, 0, /*  ** ******** **  */
    0xff, 0xff, 0, 0, /* **************** */
    0xff, 0xff, 0, 0, /* **************** */
    0xff, 0xff, 0, 0, /* **************** */
    0xff, 0xff, 0, 0, /* **************** */
    0x73, 0xce, 0, 0, /*  ***  ****  ***  */
    0x73, 0xce, 0, 0, /*  ***  ****  ***  */
    0x3f, 0xfc, 0, 0, /*   ************   */
    0x1f, 0xf8, 0, 0, /*    **********    */
    0x0f, 0xf0, 0, 0, /*     ********     */
    0x03, 0xc0, 0, 0  /*       ****       */
  };

void init(void)
{
   glPixelStorei (GL_UNPACK_ALIGNMENT, 1);
   glClearColor (0.0, 0.0, 0.0, 0.0);
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);
   glRasterPos2i (20, 20);
//    glBitmap (32, 32, 0.0, 0.0, 11.0, 0.0, rasters);
  glPixelTransferi(GL_UNPACK_ALIGNMENT, 4);
  glPixelTransferi(GL_INDEX_OFFSET, 1);
    glDrawPixels(16,16, GL_COLOR_INDEX, GL_BITMAP, smiley);
   glFlush();
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho (0, w, 0, h, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(100, 100);
   glutInitWindowPosition(100, 100);
   glutCreateWindow(argv[0]);
   init();
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}
