import com.jogamp.opengl.*;
import com.jogamp.opengl.awt.GLJPanel;
import com.jogamp.opengl.glu.GLU;
import javafx.geometry.Point2D;

import java.util.List;
import java.util.Set;

public class Baseball {

    private int type = 0;

    private Set<Point2D> listaPontosProibidos;
    private List<Ponto> listaPontosArquibancada;
    private int lineWidth;

    private double r;
    private double g;
    private double b;

    public Baseball(Set<Point2D> listaPontosProibidos, List<Ponto> listaPontosArquibancada){
        this.listaPontosProibidos = listaPontosProibidos;
        this.listaPontosArquibancada = listaPontosArquibancada;
        this.lineWidth = 0;
    }

    protected void setup( GL2 gl2, int width, int height ) {
        gl2.glMatrixMode( GL2.GL_PROJECTION );
        gl2.glLoadIdentity();

        // coordinate system origin at lower left with width and height same as the window
        GLU glu = new GLU();
        glu.gluOrtho2D(0.0f, width, 0.0f, height);

        gl2.glMatrixMode( GL2.GL_MODELVIEW );
        gl2.glLoadIdentity();

        gl2.glViewport(0, 0, width, height);
    }

    protected void plotPoint(GLJPanel display, double x, double y, double x1, double y1){
        Point2D firstPoint = new Point2D(x, display.getSurfaceHeight() - y);
        Point2D secondPoint = new Point2D(x1, display.getSurfaceHeight() - y1);

        if(!listaPontosProibidos.contains(firstPoint) || !listaPontosProibidos.contains(secondPoint)) {
            Point2D[] point2DS = new Point2D[2];

            point2DS[0] = firstPoint;
            point2DS[1] = secondPoint;

            Ponto ponto = new Ponto(point2DS, r, g, b, lineWidth);

            listaPontosArquibancada.add(ponto);
        }

        display.repaint();
    }

    protected void render(GL2 gl2, int width, int height) {
        gl2.glClearColor(0.9f, 0.6f, 0.1f, 1.0f);
        gl2.glClear(GL.GL_COLOR_BUFFER_BIT);

        if(type == 0) {
            EquacaoReta.display(gl2, listaPontosArquibancada, listaPontosProibidos, width, height, lineWidth);
        }else{
            Bresenham.display(gl2, listaPontosArquibancada, listaPontosProibidos, width, height, lineWidth);
        }
    }

    public void setColor(double r, double g, double b){
        this.r = r;
        this.g = g;
        this.b = b;
    }

    public void setLineWidth(int lineWidth) {
        this.lineWidth = lineWidth;
    }

    public void setType(int type) {
        this.type = type;
    }
}
