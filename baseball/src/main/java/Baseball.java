import com.jogamp.newt.event.WindowAdapter;
import com.jogamp.newt.opengl.GLWindow;
import com.jogamp.newt.event.WindowEvent;
import com.jogamp.opengl.*;
import com.jogamp.opengl.fixedfunc.GLMatrixFunc;
import com.jogamp.opengl.glu.GLU;
import com.jogamp.opengl.util.FPSAnimator;

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

        gl2.glViewport( 0, 0, width, height );
    }

    protected void render( GL2 gl2, int width, int height ) {
        if(type == 0) {
            gl2.glClear(GL.GL_COLOR_BUFFER_BIT);

            // draw a triangle filling the window
            gl2.glLoadIdentity();
            gl2.glBegin(GL.GL_LINES);
            gl2.glColor3f(0.95f, 0.88f, 0.11f);

            for(int i = 50; i < 310; i++){

                double theta = (i * Math.PI) / 360;

                double x = width/2 + height/2 * Math.cos(theta);
                double y = (height-400) + height/2 * Math.sin(theta);

                gl2.glVertex2d( width/2, (height-400));
                gl2.glVertex2d(x, y);
            }

            gl2.glEnd();

            gl2.glBegin(GL.GL_LINES);
            gl2.glColor3f(0, 1, 0);

            for(int i = 0; i < 360; i++){

                double theta = (2 * i * Math.PI) / 360;

                double x = width/2 + 25 * Math.cos(theta);
                double y = (height-400) + 25 * Math.sin(theta);

                gl2.glVertex2d( width/2, (height-400));
                gl2.glVertex2d(x, y);
            }

            gl2.glEnd();

        }
    }

    public void setType(int type) {
        this.type = type;
    }
}
