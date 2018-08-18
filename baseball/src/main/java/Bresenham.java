import com.jogamp.opengl.GL2;
import javafx.geometry.Point2D;

import java.util.List;
import java.util.Set;

public class Bresenham {

    public static void display(GL2 gl2, List<Ponto> listaPontosArquibancada, Set<Point2D> listaPontosProibidos, int width, int height, int lineWidth){


        //Banco dos treinadores

        line(width/2 + 75, height-560, width/2 + 100, height-530, gl2, 1, 1, 1);
        line(width/2 - 75, height-560, width/2 - 100, height-530, gl2, 1, 1, 1);
        line(width/2 + 75, height-560, width/2 + 85, height-570, gl2, 1, 1, 1);
        line(width/2 + 100, height-530, width/2 + 110, height-540, gl2, 1, 1, 1);
        line(width/2 - 75, height-560, width/2 - 85, height-570, gl2, 1, 1, 1);
        line(width/2 - 100, height-530, width/2 - 110, height-540, gl2, 1, 1, 1);

        gl2.glLineWidth(lineWidth);

        for (Ponto point2DS : listaPontosArquibancada){
            line(point2DS.getPoint2DS()[0].getX(), point2DS.getPoint2DS()[0].getY(), point2DS.getPoint2DS()[1].getX(), point2DS.getPoint2DS()[1].getY(), gl2, point2DS.getR(), point2DS.getG(), point2DS.getB());
        }

    }

    private static void arc(){
        
    }

    private static void line(double x0, double y0, double x1, double y1, GL2 gl2, double r, double g, double b){
        boolean steep = false;

        if(Math.abs(x0 - x1) < Math.abs(y0 - y1)){
            double aux = x0;
            x0 = y0;
            y0 = aux;

            aux = x1;
            x1 = y1;
            y1 = aux;

            steep = true;
        }

        if(x0 > x1){
            double aux = x0;
            x0 = x1;
            x1 = aux;

            aux = y0;
            y0 = y1;
            y1 = aux;
        }

        double dx = x1 - x0;
        double dy = y1 - y0;

        double derror = Math.abs(dy)*2;
        int error = 0;
        double y = y0;

        gl2.glBegin(GL2.GL_POINTS);
        gl2.glColor3d(r, g, b);
        for(double x = x0; x <= x1; x++){
            if(steep){
                gl2.glVertex2d(y, x);
            } else {
                gl2.glVertex2d(x, y);
            }

            error += derror;

            if(error > dx){
                y += (y1 > y0 ? 1 : -1);
                error -= dx*2;
            }
        }
        gl2.glEnd();

    }

}
