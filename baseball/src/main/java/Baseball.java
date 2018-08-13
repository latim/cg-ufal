import com.jogamp.opengl.*;
import com.jogamp.opengl.glu.GLU;

public class Baseball {

    private int type = 0;

    protected void setup( GL2 gl2, int width, int height ) {
        gl2.glMatrixMode( GL2.GL_PROJECTION );
        gl2.glLoadIdentity();

        // coordinate system origin at lower left with width and height same as the window
        GLU glu = new GLU();
        glu.gluOrtho2D( 0.0f, width, 0.0f, height );

        gl2.glMatrixMode( GL2.GL_MODELVIEW );
        gl2.glLoadIdentity();

        gl2.glViewport(0, 0, width, height);
    }

    protected void render( GL2 gl2, int width, int height ) {
        System.out.println(height);
        gl2.glClearColor(0.9f, 0.6f, 0.1f, 1.0f);
        gl2.glClear(GL.GL_COLOR_BUFFER_BIT);

        if(type == 0) {


            gl2.glLoadIdentity();

            gl2.glBegin(GL2.GL_TRIANGLE_FAN);
            gl2.glColor3f(0, 1, 0);

            int centro_x = width/2;
            int centro_y = (height - 490);
            int raio = ((height/2 - 190));

            gl2.glVertex2d(centro_x, centro_y);
            for(int i = 0; i <= 360; i++){

                double theta = (2 * i * Math.PI) / 360.0;

                double x = centro_x + raio * -Math.cos(theta);
                double y = centro_y + raio * -Math.sin(theta);

                gl2.glVertex2d(x, y);
            }

            gl2.glEnd();

            gl2.glBegin(GL.GL_TRIANGLE_FAN);
            gl2.glColor3f(0, 1, 0);
            gl2.glVertex2d( width/2, (height-640));

            for(int i = 100; i <= 260; i++){

                double theta = (i * Math.PI) / 360;

                double x = width/2 + ((height/2) + 70)  * Math.cos(theta);
                double y = (height-640) + ((height/2) + 70) * Math.sin(theta);


                gl2.glVertex2d(x, y);
            }

            gl2.glEnd();

            gl2.glBegin(GL.GL_TRIANGLE_FAN);
            gl2.glColor3f(0.95f, 0.88f, 0.11f);
            gl2.glVertex2d( width/2, (height-640));

            for(int i = 100; i <= 260; i++){

                double theta = (i * Math.PI) / 360;

                double x = width/2 + (height/2 - 100) * Math.cos(theta);
                double y = (height-640) + (height/2 - 100) * Math.sin(theta);


                gl2.glVertex2d(x, y);
            }

            gl2.glEnd();

            //parte do meio

            gl2.glBegin(GL.GL_TRIANGLE_FAN);
            gl2.glColor3f(0, 1, 0);
            gl2.glVertex2d(width/2 - 90, (height - 520));
            gl2.glVertex2d(width/2, (height-430));
            gl2.glVertex2d(width/2 + 90, (height - 520));
            gl2.glVertex2d(width/2, (height-625));
            gl2.glEnd();

            gl2.glBegin(GL.GL_TRIANGLE_FAN);
            gl2.glColor3f(0.95f, 0.88f, 0.11f);

            gl2.glVertex2d(width/2 + 90, (height - 520));


            for(int i = 180; i <= 270; i++){

                double theta = (i * Math.PI) / 360;

                double x = width/2 + 90 + 17 * Math.cos(theta);
                double y =  (height - 520) + 17 * Math.sin(theta);


                gl2.glVertex2d(x, y);
            }


            for(int i = 360; i <= 500; i++){

                double theta = (i * Math.PI) / 360;

                double x = width/2 + 90 + 17 * Math.cos(theta);
                double y =  (height - 520) + 17 * Math.sin(theta);


                gl2.glVertex2d(x, y);
            }

            gl2.glEnd();

            gl2.glBegin(GL.GL_TRIANGLE_FAN);
            gl2.glColor3f(0.95f, 0.88f, 0.11f);

            gl2.glVertex2d(width/2, (height-430));

            for(int i = 0; i <= 360; i++){

                double theta = (i * Math.PI) / 360;

                double x = width/2 + 17 * -Math.cos(theta);
                double y = (height-430) + 17 * -Math.sin(theta);


                gl2.glVertex2d(x, y);
            }

            gl2.glEnd();

            gl2.glBegin(GL.GL_TRIANGLE_FAN);
            gl2.glColor3f(0.95f, 0.88f, 0.11f);

            gl2.glVertex2d(width/2 - 90, (height - 520));

            for(int i = 0; i <= 180; i++){

                double theta = (i * Math.PI) / 360;

                double x = (width/2 - 90) + 17 * Math.cos(theta);
                double y = (height - 520) + 17 * Math.sin(theta);

                gl2.glVertex2d(x, y);
            }

            for(int i = 600; i <= 720; i++){

                double theta = (i * Math.PI) / 360;

                double x = (width/2 - 90) + 17 * Math.cos(theta);
                double y = (height - 520) + 17 * Math.sin(theta);

                gl2.glVertex2d(x, y);
            }

            gl2.glEnd();


            gl2.glBegin(GL.GL_TRIANGLE_FAN);
            gl2.glColor3f(0.95f, 0.88f, 0.11f);
            gl2.glVertex2d( width/2, (height - 530));

            for(int i = 0; i < 360; i++){

                double theta = (2 * i * Math.PI) / 360;

                double x = width/2 + 17 * Math.cos(theta);
                double y = (height - 530) + 17 * Math.sin(theta);


                gl2.glVertex2d(x, y);
            }

            gl2.glEnd();

            //fim meio

            gl2.glBegin(GL.GL_TRIANGLE_FAN);
            gl2.glColor3f(0.95f, 0.88f, 0.11f);
            gl2.glVertex2d( width/2, (height-640));

            for(int i = 0; i < 360; i++){

                double theta = (2 * i * Math.PI) / 360;

                double x = width/2 + 25 * Math.cos(theta);
                double y = (height-640) + 25 * Math.sin(theta);


                gl2.glVertex2d(x, y);
            }

            gl2.glEnd();


            //retangulos dos rebatedores

            gl2.glBegin(GL.GL_TRIANGLE_FAN);
            gl2.glColor3f(1, 1, 1);
            gl2.glVertex2d(width/2 - 10, height - 632);
            gl2.glVertex2d(width/2 - 3, height - 632);
            gl2.glVertex2d(width/2 - 3, height - 642);
            gl2.glVertex2d(width/2 - 10, height - 642);
            gl2.glEnd();

            gl2.glBegin(GL.GL_TRIANGLE_FAN);
            gl2.glColor3f(1, 1, 1);
            gl2.glVertex2d(width/2 + 10, height - 632);
            gl2.glVertex2d(width/2 + 3, height - 632);
            gl2.glVertex2d(width/2 + 3, height - 642);
            gl2.glVertex2d(width/2 + 10, height - 642);
            gl2.glEnd();

            gl2.glBegin(GL.GL_TRIANGLE_FAN);
            gl2.glColor3f(1, 1, 1);
            gl2.glVertex2d(width/2 - 3, height - 642);
            gl2.glVertex2d(width/2 + 3, height - 642);
            gl2.glVertex2d(width/2 + 3, height - 652);
            gl2.glVertex2d(width/2 - 3, height - 652);
            gl2.glEnd();

            //Banco dos treinadores

            gl2.glLineWidth(2);
            gl2.glBegin(GL2.GL_LINES);
            gl2.glColor3f(1, 1, 1);
            gl2.glVertex2d(width/2 + 75, height-560);
            gl2.glVertex2d(width/2 + 100, height-530);
            gl2.glEnd();

            gl2.glLineWidth(2);
            gl2.glBegin(GL2.GL_LINES);
            gl2.glColor3f(1, 1, 1);
            gl2.glVertex2d(width/2 - 75, height-560);
            gl2.glVertex2d(width/2 - 100, height-530);
            gl2.glEnd();

            gl2.glLineWidth(2);
            gl2.glBegin(GL2.GL_LINES);
            gl2.glColor3f(1, 1, 1);
            gl2.glVertex2d(width/2 + 75, height-560);
            gl2.glVertex2d(width/2 + 85, height-570);
            gl2.glEnd();

            gl2.glLineWidth(2);
            gl2.glBegin(GL2.GL_LINES);
            gl2.glColor3f(1, 1, 1);
            gl2.glVertex2d(width/2 + 100, height-530);
            gl2.glVertex2d(width/2 + 110, height-540);
            gl2.glEnd();


            gl2.glLineWidth(2);
            gl2.glBegin(GL2.GL_LINES);
            gl2.glLineWidth(2);
            gl2.glColor3f(1, 1, 1);
            gl2.glVertex2d(width/2 - 75, height-560);
            gl2.glVertex2d(width/2 - 85, height-570);
            gl2.glEnd();


            gl2.glLineWidth(2);
            gl2.glBegin(GL2.GL_LINES);
            gl2.glColor3f(1, 1, 1);
            gl2.glVertex2d(width/2 - 100, height-530);
            gl2.glVertex2d(width/2 - 110, height-540);
            gl2.glEnd();

        }
    }

    public void setType(int type) {
        this.type = type;
    }
}
