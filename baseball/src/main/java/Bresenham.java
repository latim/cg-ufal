import com.jogamp.opengl.GL2;
import javafx.geometry.Point2D;

import java.util.List;
import java.util.Set;

public class Bresenham {

    private static int limitArc;

    public static void display(GL2 gl2, List<Ponto> listaPontosArquibancada, Set<Point2D> listaPontosProibidos, int width, int height, int lineWidth){

        limitArc = 0;
        arc(width/2, (height - 490), ((height/2 - 190)), gl2, 0.6f, 0.8f, 0.2f, true, true, true, true, true, true, true, true);
        limitArc = 295;
        arc(width/2, (height - 640), ((height/2) + 70), gl2, 0.6, 0.8, 0.2, false, true, true, false, false, false, false, false);
        limitArc = 185;
        arc(width/2, (height - 640), (height/2 - 100), gl2, 0.95f, 0.88f, 0.11f, false, true, true, false, false, false, false, false);
        limitArc = 0;

        //quadrado do meio
        line(width/2 - 90, height-520, width/2, height-430, gl2, 0.1f, 1f, 0.2f, 1);
        line(width/2 + 90, height-520, width/2, height-625, gl2, 0.1f, 1f, 0.2f, 1);
        line(width/2, (height-430), width/2 + 90, (height - 520), gl2, 0.1f, 1f, 0.2f, 1);
        line(width/2 - 90, (height - 520), width/2, (height-625), gl2, 0.1f, 1f, 0.2f, 1);

        int x0 = width/2 - 90;
        int x1 = width/2;
        int fx0 = width/2;
        int fx1 = width/2 + 90;
        int y0 = height-520;
        int y1 = height-430;
        int fy0 = height-625;
        int fy1 = height-520;

        int i, j, w, z;

        for(i = x0, j = x1, w = y0, z = y1; i <= fx0 && j <= fx1 && w >= fy0 && z >= fy1; i += 1, j += 1, w--, z--){
            line(i, w, j, z, gl2,0.1f, 1f, 0.2f, 3);
        }

        //circulos do meio
        arc(width/2 + 90, (height - 520), 17, gl2, 0.95f, 0.88f, 0.11f, false, false, true, true, true, true, false, false);
        arc(width/2, (height - 430), 17, gl2, 0.95f, 0.88f, 0.11f, false, false, false, false, true, true, true, true);
        arc(width/2 - 90, (height - 520), 17, gl2, 0.95f, 0.88f, 0.11f, true, true, false, false, false, false, true, true);
        arc(width/2, (height - 530), 17, gl2, 0.95f, 0.88f, 0.11f, true, true, true, true, true, true, true, true);

        //circulo dos batedores
        arc(width/2, (height - 640),25, gl2, 0.95f, 0.88f, 0.11f, true, true, true, true, true, true, true, true);

        //retangulo dos rebatedores
        line(width/2 - 10, height - 632, width/2 - 3, height - 632, gl2, 1, 1, 1, 2);
        line(width/2 - 3, height - 642, width/2 - 10, height - 642, gl2, 1, 1, 1, 2);
        line(width/2 - 10, height - 632, width/2 - 10, height - 642, gl2, 1, 1, 1, 2);
        line(width/2 - 3, height - 632, width/2 - 3, height - 642, gl2, 1, 1, 1, 2);

        line(width/2 + 10, height - 632, width/2 + 3, height - 632, gl2, 1, 1, 1, 2);
        line(width/2 + 3, height - 642, width/2 + 10, height - 642, gl2, 1, 1, 1, 2);
        line(width/2 + 10, height - 632, width/2 + 10, height - 642, gl2, 1, 1, 1, 2);
        line(width/2 + 3, height - 632, width/2 + 3, height - 642, gl2, 1, 1, 1, 2);

        line(width/2 - 3, height - 642, width/2 + 3, height - 642, gl2, 1, 1, 1, 2);
        line(width/2 + 3, height - 652, width/2 - 3, height - 652, gl2, 1, 1, 1, 2);
        line(width/2 - 3, height - 642, width/2 - 3, height - 652, gl2, 1, 1, 1, 2);
        line(width/2 + 3, height - 642, width/2 + 3, height - 652, gl2, 1, 1, 1, 2);

        //Banco dos treinadores
        line(width/2 + 75, height-560, width/2 + 100, height-530, gl2, 1, 1, 1, 2);
        line(width/2 - 75, height-560, width/2 - 100, height-530, gl2, 1, 1, 1, 2);
        line(width/2 + 75, height-560, width/2 + 85, height-570, gl2, 1, 1, 1, 2);
        line(width/2 + 100, height-530, width/2 + 110, height-540, gl2, 1, 1, 1, 2);
        line(width/2 - 75, height-560, width/2 - 85, height-570, gl2, 1, 1, 1, 2);
        line(width/2 - 100, height-530, width/2 - 110, height-540, gl2, 1, 1, 1, 2);

        for (Ponto point2DS : listaPontosArquibancada){
            line(point2DS.getPoint2DS()[0].getX(), point2DS.getPoint2DS()[0].getY(), point2DS.getPoint2DS()[1].getX(), point2DS.getPoint2DS()[1].getY(), gl2, point2DS.getR(), point2DS.getG(), point2DS.getB(), point2DS.getTamanho());
        }

    }

    private static void plotPoint(double x, double y, double r, double g, double b, int pointSize, GL2 gl2){
        gl2.glPointSize(pointSize);
        gl2.glBegin(GL2.GL_POINTS);
        gl2.glColor3d(r, g, b);
        gl2.glVertex2d(x, y);
        gl2.glEnd();
    }

    private static void arc(double x0, double y0, int raio, GL2 gl2, double r, double g, double b, boolean oct1, boolean oct2, boolean oct3, boolean oct4, boolean oct5, boolean oct6, boolean oct7, boolean oct8){
        double x = raio - 1;
        double y = 0;
        double dx = 1;
        double dy = 1;
        double err = dx - (raio << 1);
        int count = 0;
        int count3 = 0;

        while (x >= y){

            if(oct1){
                plotPoint(x0 + x, y0 + y, r, g, b, 1, gl2);
                line(x0, y0, x0 + x, y0 + y, gl2, r, g, b, 1);
            }

            if(oct2){
                if(limitArc != 0){
                    if(count <= limitArc){
                        plotPoint(x0 + y, y0 + x, r, g, b, 1, gl2);
                        line(x0, y0, x0 + y, y0 + x, gl2, r, g, b, 1);
                    }
                    count++;
                }else{
                    plotPoint(x0 + y, y0 + x, r, g, b, 1, gl2);
                    line(x0, y0, x0 + y, y0 + x, gl2, r, g, b, 1);
                }
            }

            if(oct3){
                if(limitArc != 0){
                    if(count3 <= limitArc){
                        plotPoint(x0 - y, y0 + x, r, g, b, 1, gl2);
                        line(x0, y0, x0 - y, y0 + x, gl2, r, g, b, 1);
                    }
                    count3++;
                }else{
                    plotPoint(x0 - y, y0 + x, r, g, b, 1, gl2);
                    line(x0, y0, x0 - y, y0 + x, gl2, r, g, b, 1);
                }
            }

            if(oct4){
                plotPoint(x0 - x, y0 + y, r, g, b, 1, gl2);
                line(x0, y0, x0 - x, y0 + y, gl2, r, g, b, 1);
            }

            if(oct5){
                plotPoint(x0 - x, y0 - y, r, g, b, 1, gl2);
                line(x0, y0, x0 - x, y0 - y, gl2, r, g, b, 1);
            }

            if(oct6){
                plotPoint(x0 - y, y0 - x, r, g, b, 1, gl2);
                line(x0, y0, x0 - y, y0 - x, gl2, r, g, b, 1);
            }

            if(oct7){
                plotPoint(x0 + y, y0 - x, r, g, b, 1, gl2);
                line(x0, y0, x0 + y, y0 - x, gl2, r, g, b, 1);
            }

            if(oct8){
                plotPoint(x0 + x, y0 - y, r, g, b, 1, gl2);
                line(x0, y0, x0 + x, y0 - y, gl2, r, g, b, 1);
            }

            if(err <= 0){
                y++;
                err += dy;
                dy += 2;
            }

            if(err > 0){
                x--;
                dx += 2;
                err += dx - (raio << 1);
            }

        }
        System.out.println(count3);
    }

    private static void line(double x0, double y0, double x1, double y1, GL2 gl2, double r, double g, double b, int pointSize){
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

        for(double x = x0; x <= x1; x++){
            if(steep){
                plotPoint(y, x, r, g, b, pointSize, gl2);
            } else {
                plotPoint(x, y, r, g, b, pointSize, gl2);
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
