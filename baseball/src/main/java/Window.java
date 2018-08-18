import com.jogamp.opengl.GLAutoDrawable;
import com.jogamp.opengl.GLEventListener;
import com.jogamp.opengl.GLProfile;
import com.jogamp.opengl.GLCapabilities;
import com.jogamp.opengl.awt.GLJPanel;

import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.HashSet;

public class Window {

    private static final int TICK_MIN = 0;
    private static final int TICK_INIT = 2;
    private static final int TICK_MAX = 10;

    private static double firstX;
    private static double firstY;

    private static boolean second = false;

    public static void main( String [] args ) {
        GLProfile glprofile = GLProfile.getDefault();
        GLCapabilities glcapabilities = new GLCapabilities( glprofile );
        GLJPanel gljpanel = new GLJPanel( glcapabilities );

        JPanel botoes = new JPanel();

        Baseball baseball = new Baseball(new HashSet<>(), new ArrayList<>());

        gljpanel.addGLEventListener( new GLEventListener() {

            @Override
            public void reshape( GLAutoDrawable glautodrawable, int x, int y, int width, int height ) {
                baseball.setup( glautodrawable.getGL().getGL2(), width, height );
            }

            @Override
            public void init( GLAutoDrawable glautodrawable ) {
            }

            @Override
            public void dispose( GLAutoDrawable glautodrawable ) {
            }

            @Override
            public void display( GLAutoDrawable glautodrawable ) {
                baseball.render( glautodrawable.getGL().getGL2(), glautodrawable.getSurfaceWidth(), glautodrawable.getSurfaceHeight() );
            }
        });

        gljpanel.addMouseListener(new MouseListener() {
            @Override
            public void mouseClicked(MouseEvent e) {
                if(second) {
                    second = false;
                    baseball.plotPoint(gljpanel, firstX, firstY, e.getX(), e.getY());
                } else {
                    second = true;
                    firstX = e.getX();
                    firstY = e.getY();
                }
            }

            @Override
            public void mousePressed(MouseEvent e) {

            }

            @Override
            public void mouseReleased(MouseEvent e) {

            }

            @Override
            public void mouseEntered(MouseEvent e) {

            }

            @Override
            public void mouseExited(MouseEvent e) {

            }
        });

        JRadioButton retaButton = new JRadioButton("Equação da reta");
        JRadioButton bressButton = new JRadioButton("Bressham");

        retaButton.setSelected(true);

        JSlider espessura = new JSlider(JSlider.HORIZONTAL, TICK_MIN, TICK_MAX, TICK_INIT);

        espessura.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                baseball.setLineWidth(espessura.getValue());
            }
        });

        JLabel lOpcao = new JLabel("Escolha o tipo de modelagem");
        JLabel lEspessura = new JLabel("Escolha a espessura das retas");

        ButtonGroup buttonGroup = new ButtonGroup();
        buttonGroup.add(retaButton);
        buttonGroup.add(bressButton);

        JButton botaoCor = new JButton("Selecione a cor");
        botaoCor.setOpaque(true);
        botaoCor.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Color color = JColorChooser.showDialog(null, "Escolha a cor para as retas", Color.BLUE);
                System.out.println(color);

                if(color != null) {
                    botaoCor.setBackground(color);
                    baseball.setColor(color.getRed()/255, color.getGreen(), color.getBlue());
                }

            }
        });

        botoes.setLayout(new BoxLayout(botoes, BoxLayout.Y_AXIS));
        botoes.add(lOpcao);
        botoes.add(retaButton);
        botoes.add(bressButton);
        botoes.add(lEspessura);
        botoes.add(espessura);
        botoes.add(botaoCor);

        final JFrame jframe = new JFrame( "Baseball" );
        jframe.addWindowListener( new WindowAdapter() {
            public void windowClosing( WindowEvent windowevent ) {
                jframe.dispose();
                System.exit( 0 );
            }
        });

        Container pane = jframe.getContentPane();
        pane.setLayout(new BorderLayout());

        pane.add(botoes, BorderLayout.LINE_START);
        pane.add(gljpanel, BorderLayout.CENTER);

        jframe.setSize( 800, 800 );
        jframe.setVisible( true );
    }

}
