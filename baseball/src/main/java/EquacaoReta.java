import com.jogamp.opengl.GL;
import com.jogamp.opengl.GL2;
import javafx.geometry.Point2D;

import java.util.List;
import java.util.Set;

public class EquacaoReta {

    public static void display(GL2 gl2, List<Ponto> listaPontosArquibancada, Set<Point2D> listaPontosProibidos, int width, int height, int lineWidth) {
        gl2.glLoadIdentity();

        gl2.glLineWidth(2);

        gl2.glBegin(GL2.GL_TRIANGLE_FAN);
        gl2.glColor3f(0.6f, 0.8f, 0.2f);

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
        gl2.glColor3f(0.6f, 0.8f, 0.2f);
        gl2.glVertex2d( width/2, (height-640));

        for(int i = 100; i <= 260; i++){
            double theta = (i * Math.PI) / 360;

            double x = width/2 + ((height/2) + 70)  * Math.cos(theta);
            double y = (height-640) + ((height/2) + 70) * Math.sin(theta);

            listaPontosProibidos.add(new Point2D(x, y));

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
        gl2.glColor3f(0.6f, 1f, 0.2f);
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

        gl2.glBegin(GL.GL_LINE_LOOP);
        gl2.glColor3f(1, 1, 1);
        gl2.glVertex2d(width/2 - 10, height - 632);
        gl2.glVertex2d(width/2 - 3, height - 632);
        gl2.glVertex2d(width/2 - 3, height - 642);
        gl2.glVertex2d(width/2 - 10, height - 642);
        gl2.glEnd();

        gl2.glBegin(GL.GL_LINE_LOOP);
        gl2.glColor3f(1, 1, 1);
        gl2.glVertex2d(width/2 + 10, height - 632);
        gl2.glVertex2d(width/2 + 3, height - 632);
        gl2.glVertex2d(width/2 + 3, height - 642);
        gl2.glVertex2d(width/2 + 10, height - 642);
        gl2.glEnd();

        gl2.glBegin(GL.GL_LINE_LOOP);
        gl2.glColor3f(1, 1, 1);
        gl2.glVertex2d(width/2 - 3, height - 642);
        gl2.glVertex2d(width/2 + 3, height - 642);
        gl2.glVertex2d(width/2 + 3, height - 652);
        gl2.glVertex2d(width/2 - 3, height - 652);
        gl2.glEnd();

        //Banco dos treinadores

        gl2.glBegin(GL2.GL_LINES);
        gl2.glColor3f(1, 1, 1);
        gl2.glVertex2d(width/2 + 75, height-560);
        gl2.glVertex2d(width/2 + 100, height-530);
        gl2.glEnd();

        gl2.glBegin(GL2.GL_LINES);
        gl2.glColor3f(1, 1, 1);
        gl2.glVertex2d(width/2 - 75, height-560);
        gl2.glVertex2d(width/2 - 100, height-530);
        gl2.glEnd();

        gl2.glBegin(GL2.GL_LINES);
        gl2.glColor3f(1, 1, 1);
        gl2.glVertex2d(width/2 + 75, height-560);
        gl2.glVertex2d(width/2 + 85, height-570);
        gl2.glEnd();

        gl2.glBegin(GL2.GL_LINES);
        gl2.glColor3f(1, 1, 1);
        gl2.glVertex2d(width/2 + 100, height-530);
        gl2.glVertex2d(width/2 + 110, height-540);
        gl2.glEnd();

        gl2.glBegin(GL2.GL_LINES);
        gl2.glColor3f(1, 1, 1);
        gl2.glVertex2d(width/2 - 75, height-560);
        gl2.glVertex2d(width/2 - 85, height-570);
        gl2.glEnd();

        gl2.glBegin(GL2.GL_LINES);
        gl2.glColor3f(1, 1, 1);
        gl2.glVertex2d(width/2 - 100, height-530);
        gl2.glVertex2d(width/2 - 110, height-540);
        gl2.glEnd();

        //plotagem dos pontos

        for (Ponto point2DS : listaPontosArquibancada){
            gl2.glBegin(GL2.GL_LINES);
            gl2.glLineWidth(point2DS.getTamanho());
            gl2.glColor3d(point2DS.getR(), point2DS.getG(), point2DS.getB());
            gl2.glVertex2d(point2DS.getPoint2DS()[0].getX(), point2DS.getPoint2DS()[0].getY());
            gl2.glVertex2d(point2DS.getPoint2DS()[1].getX(), point2DS.getPoint2DS()[1].getY());
            gl2.glEnd();
        }
    }

}
