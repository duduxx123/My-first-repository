import java.io.*;
import java.net.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
class GUIClient1  extends JFrame  
{	JTextField tf;
	JButton  bt;
	JTextArea ta;
	BufferedReader din;
	BufferedWriter dout;
	GUIClient1(String s)
	{	super(s);
		setSize(400, 500);
		setLayout(new FlowLayout());
		tf=new JTextField(30);
		bt=new JButton("发送");
		ta=new JTextArea(20,30);
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
	private void communication()
	{	try
		{	Socket sk=new Socket("127.0.0.1", 15500);
			InputStream in=sk.getInputStream();
			OutputStream out=sk.getOutputStream();
			din=new BufferedReader(new InputStreamReader(in));
			dout=new BufferedWriter(new  OutputStreamWriter(out));
			String s1;
			do
			{	s1=din.readLine();
				ta.append("Server: "+s1+"\n");
			}while(!s1.equals("BYE"));
			sk.close();
		}catch(IOException ee){}
	}
	class  Handler 	implements ActionListener
	{	public void actionPerformed(ActionEvent e)
		{	String s=tf.getText();
			ta.append("Client:  "+s+"\n");
			tf.setText("");
			try{	dout.write(s);
				dout.newLine();
				dout.flush();
			}catch(IOException ee){}
		}
	}
	public static void main(String[] args)
	{	new GUIClient1("Client");
	}
}
