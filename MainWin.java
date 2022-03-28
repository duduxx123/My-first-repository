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
	JLabel lblNewLabel = new JLabel("第几关");
	JLabel lblNewLabel_1 = new JLabel("第几关");
	//创建游戏对象
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
		
		JButton btnNewButton = new JButton("重新开始");
		panel_1.add(btnNewButton);
		
		//loadMap(1);
		game.start();
		//加载关数
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
		
		JButton btnNewButton_2 = new JButton("上一关");
		panel_1.add(btnNewButton_2);
		
		JButton btnNewButton_1 = new JButton("下一关");
		
		panel_1.add(btnNewButton_1);
		comboBox.setModel(new DefaultComboBoxModel(new String[] {"第一关", "第二关", "第三关", "第四关","第五关","第六关","第七关"}));
		panel_1.add(comboBox);
		comboBox.setPreferredSize(new Dimension(80,25));
		//JLabel lblNewLabel = new JLabel("第几关");
		panel_1.add(lblNewLabel);
		panel_1.add(lblNewLabel_1);
		pack();
		
		/**
		 * 全局键盘事件
		 */
		KeyboardFocusManager manager = KeyboardFocusManager.getCurrentKeyboardFocusManager();
		manager.addKeyEventPostProcessor(new KeyEventPostProcessor() {
			boolean isShowMsg=false;
			/**
			 * event 事件对象
			 */
			public boolean postProcessKeyEvent(KeyEvent event) {
				// 判断当前是按键按下的事件
				if (event.getID() != KeyEvent.KEY_PRESSED) {
					return false;
				}
				if(isShowMsg)
					return false;
				// getKeyCode 获取当前按下的按键
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
					JOptionPane.showMessageDialog(null, "居然被你过关了！用了"+game.bushu()+"步");
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
		//重新开始当前关
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
			//清空内部图片
			//panel.removeAll();
			lblNewLabel.setText("第"+game.getLevel()+"关");
			lblNewLabel_1.setText("已用步数:"+game.bushu());
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
					//将图片设置到label中
					label.setIcon(icon);
				}
			}
			
		}
		
		

}
