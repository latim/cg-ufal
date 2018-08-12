import com.jogamp.opengl.GLAutoDrawable;
import com.jogamp.opengl.GLEventListener;
import com.jogamp.opengl.GLProfile;
import com.jogamp.opengl.GLCapabilities;
import com.jogamp.opengl.awt.GLJPanel;

import javax.swing.*;

import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Window {

    static final int TICK_MIN = 0;
    static final int TICK_INIT = 2;
    static final int TICK_MAX = 10;

    public static void main( String [] args ) {
        GLProfile glprofile = GLProfile.getDefault();
        GLCapabilities glcapabilities = new GLCapabilities( glprofile );
        GLJPanel gljpanel = new GLJPanel( glcapabilities );

        Baseball baseball = new Baseball();

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

        JRadioButton retaButton = new JRadioButton("Equação da reta");
        JRadioButton bressButton = new JRadioButton("Bressham");

        JSlider espessura = new JSlider(JSlider.HORIZONTAL, TICK_MIN, TICK_MAX, TICK_INIT);

        JLabel lOpcao = new JLabel("Escolha o tipo de modelagem");
        JLabel lEspessura = new JLabel("Escolha a espessura das retas");

        ButtonGroup buttonGroup = new ButtonGroup();
        buttonGroup.add(retaButton);
        buttonGroup.add(bressButton);

        JPanel botoes = new JPanel();
        botoes.setLayout(new BoxLayout(botoes, BoxLayout.Y_AXIS));
        botoes.add(lOpcao);
        botoes.add(retaButton);
        botoes.add(bressButton);
        botoes.add(lEspessura);
        botoes.add(espessura);

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
