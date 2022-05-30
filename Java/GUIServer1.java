import java.io.*;
import java.net.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
class GUIServer1  extends JFrame  
{	JTextField tf;
	JTextArea ta;
	JButton  bt;
	BufferedReader din;
	BufferedWriter dout;
	GUIServer1(String s)
	{	super(s);
		setSize(400, 500);
		setLayout(new FlowLayout());
		tf=new JTextField(30);
		ta=new JTextArea(20,30);
		bt=new JButton("·¢ËÍ");
		JScrollPane sc=new JScrollPane(ta);
		add(tf);
		add(bt);
		add(sc);
		Handler d=new Handler();
		bt.addActionListener(d);
		tf.addActionListener(d);
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		communication();
	}
	private  void communication()
	{	try
		{	ServerSocket svsk=new ServerSocket(15500);
			while(true)
			{	Socket sk=svsk.accept();
				InputStream in=sk.getInputStream();
				OutputStream out=sk.getOutputStream();
				din=new BufferedReader(new InputStreamReader(in));
				dout=new BufferedWriter(new OutputStreamWriter(out));
				String s1;
				do
				{	s1=din.readLine();
					ta.append("Client: "+s1+"\n");
				}while(!s1.equals("BYE"));
				sk.close();
			}
		}catch(IOException ee){}
	}
	class Handler	implements ActionListener
	{	public void actionPerformed(ActionEvent e)
		{	String s=tf.getText();
			ta.append("Server:  "+s+"\n");
			tf.setText("");
			try{	dout.write(s);
				dout.newLine();
				dout.flush();
			}catch(IOException ee){}
		}
	}
	public static void main(String[] args) 
	{	new GUIServer1("Server");
	}
}
