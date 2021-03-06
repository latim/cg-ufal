import javafx.geometry.Point2D;

public class Ponto {

    private Point2D[] point2DS;
    private double r;
    private double g;
    private double b;
    private int tamanho;

    public Ponto(Point2D[] point2DS, double r, double g, double b, int tamanho){
        this.point2DS = point2DS;
        this.r = r;
        this.g = g;
        this.b = b;
        this.tamanho = tamanho;
    }

    public int getTamanho() {
        return tamanho;
    }

    public void setTamanho(int tamanho) {
        this.tamanho = tamanho;
    }

    public Point2D[] getPoint2DS() {
        return point2DS;
    }

    public double getR() {
        return r;
    }

    public void setR(double r) {
        this.r = r;
    }

    public double getG() {
        return g;
    }

    public void setG(double g) {
        this.g = g;
    }

    public double getB() {
        return b;
    }

    public void setB(double b) {
        this.b = b;
    }
}
