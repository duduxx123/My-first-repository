import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;

public class PicTest {
    public static void main(String[] args) {
        write w=new write();
    }
}
class write extends JPanel implements MouseMotionListener {
    int x=-10,y=-10;
    public write(){
        addMouseMotionListener(this);
        JFrame jf=new JFrame("画图版");
        jf.add(this);
        jf.setBounds(100,100,600,500);
        jf.setVisible(true);
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    @Override
    public void paintComponent(Graphics g){
        g.fillOval(x,y,9,9);
    }
    @Override
    public void mouseDragged(MouseEvent e) {
        x=e.getX();
        y=e.getY();
        repaint();
    }
    @Override
    public void mouseMoved(MouseEvent e) {}
    
}
