package com.zjd.pushbox.ui;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import com.zjd.pushbox.core.PushBoxGame;
import com.zjd.pushbox.util.MapUtil;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.GridLayout;
import java.awt.KeyEventPostProcessor;
import java.awt.KeyboardFocusManager;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;

import javax.swing.JComboBox;
import javax.swing.DefaultComboBoxModel;

public class MainWin extends JFrame {

	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	JPanel panel = new JPanel();
	JLabel lblNewLabel = new JLabel("�ڼ���");
	JLabel lblNewLabel_1 = new JLabel("�ڼ���");
	//������Ϸ����
	PushBoxGame game=new PushBoxGame();
	
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MainWin frame = new MainWin();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public MainWin() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);
		
		contentPane.add(panel, BorderLayout.CENTER);
		panel.setLayout(new GridLayout(20, 20, 0, 0));
		
		/*JLabel lblNewLabel = new JLabel("New label");
		panel.add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel("New label");
		panel.add(lblNewLabel_1);*/
		
		JPanel panel_1 = new JPanel();
		contentPane.add(panel_1, BorderLayout.EAST);
		
		JButton btnNewButton = new JButton("���¿�ʼ");
		panel_1.add(btnNewButton);
		
		//loadMap(1);
		game.start();
		//���ع���
		loadMap(game.getLevel());
		
		panel_1.setPreferredSize(new Dimension(150,0));
		
		JComboBox<String> comboBox = new JComboBox<>();
		comboBox.setFocusable(false);
		comboBox.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.out.println(comboBox.getSelectedIndex());
				game.toLevel(comboBox.getSelectedIndex()+1);
				loadMap(game.getLevel());
			}
			
		});
		
		JButton btnNewButton_2 = new JButton("��һ��");
		panel_1.add(btnNewButton_2);
		
		JButton btnNewButton_1 = new JButton("��һ��");
		
		panel_1.add(btnNewButton_1);
		comboBox.setModel(new DefaultComboBoxModel(new String[] {"��һ��", "�ڶ���", "������", "���Ĺ�","�����","������","���߹�"}));
		panel_1.add(comboBox);
		comboBox.setPreferredSize(new Dimension(80,25));
		//JLabel lblNewLabel = new JLabel("�ڼ���");
		panel_1.add(lblNewLabel);
		panel_1.add(lblNewLabel_1);
		pack();
		
		/**
		 * ȫ�ּ����¼�
		 */
		KeyboardFocusManager manager = KeyboardFocusManager.getCurrentKeyboardFocusManager();
		manager.addKeyEventPostProcessor(new KeyEventPostProcessor() {
			boolean isShowMsg=false;
			/**
			 * event �¼�����
			 */
			public boolean postProcessKeyEvent(KeyEvent event) {
				// �жϵ�ǰ�ǰ������µ��¼�
				if (event.getID() != KeyEvent.KEY_PRESSED) {
					return false;
				}
				if(isShowMsg)
					return false;
				// getKeyCode ��ȡ��ǰ���µİ���
				switch (event.getKeyCode()) {
				case KeyEvent.VK_UP:
				case KeyEvent.VK_W:
					game.moveUp();
					loadMap(game.getLevel());
					//loadMap(-1);
					break;
				case KeyEvent.VK_DOWN:
				case KeyEvent.VK_S:
					game.moveDown();
					break;
				case KeyEvent.VK_LEFT:
				case KeyEvent.VK_A:
					game.moveLeft();
					break;
				case KeyEvent.VK_RIGHT:
				case KeyEvent.VK_D:
					game.moveRight();		
					break;
				default:
					return false;
				}
				loadMap(game.getLevel());
				if(game.isWin()) {
					isShowMsg=true;
					JOptionPane.showMessageDialog(null, "��Ȼ��������ˣ�����"+game.bushu()+"��");
					game.clearstep();
					game.next();
					loadMap(game.getLevel());
					isShowMsg=false;
				}
				return false;
			}
		});
//		for (int i = 0; i < 20; i++) {
//			for (int j = 0; j < 20; j++) {
//				JLabel label = new JLabel();
//				panel.add(label);
//				ClassLoader cl=MainWin2.class.getClassLoader();
//				Icon icon = new ImageIcon(cl.getResource("com/zjd/pushbox/resource/imgs/5.GIF"));
//				label.setIcon(icon);
//			}
//		}
		
		//pack();
		//���¿�ʼ��ǰ��
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				game.restart();
				loadMap(game.getLevel());
				}
			});
		btnNewButton_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				game.next();
				loadMap(game.getLevel());
				}
			});
		btnNewButton_2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				game.last();
				loadMap(game.getLevel());
				}
			});
		
	}
		
	static Icon[] icons=new Icon[10];
	static {
		ClassLoader cl=MainWin2.class.getClassLoader();
		for (int i = 0; i < 10; i++) {
			icons[i]=new ImageIcon(cl.getResource("com/zjd/pushbox/resource/imgs/"+i+".GIF"));
		}
	}
	
		public void loadMap(int index) {
			char[][]map=game.getMap();
			//����ڲ�ͼƬ
			//panel.removeAll();
			lblNewLabel.setText("��"+game.getLevel()+"��");
			lblNewLabel_1.setText("���ò���:"+game.bushu());
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 20; j++) {
					JLabel label;
					if(panel.getComponentCount()<400) {
						label = new JLabel();
						panel.add(label);
					}else {
						label=(JLabel)panel.getComponent(i*20+j);
					}
					
					//panel.add(label);
					ClassLoader cl=MainWin2.class.getClassLoader();
					char c=map[i][j];
					//Icon icon = new ImageIcon(cl.getResource("com/zjd/pushbox/resource/imgs/"+c+".GIF"));
					Icon icon = icons[c-48];
					//��ͼƬ���õ�label��
					label.setIcon(icon);
				}
			}
			
		}
		
		

}
