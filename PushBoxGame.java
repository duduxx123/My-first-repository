package com.zjd.pushbox.core;

import com.zjd.pushbox.util.MapUtil;


//��Ϸ����ҵ����
public class PushBoxGame {
	
	private int level;
	int step=0;//ͳ�Ʋ���
//	int flag=0;//��С��ˢ��Ŀ�ĵص�BUG
//	int flag2=0;//ͬ��
	long starttime;//��ʱ
	public long time;//ͬ��
	long endtime;//ͬ��
	private char[][]map0;
	private char[][]map;
	
	//�жϵ�ǰ�ؿ��Ƿ����
	public boolean isWin() {
		for (int i = 0; i < map.length; i++) {
			for (int j = 0; j < map[i].length; j++) {
				if(map[i][j]=='3')
					return false;
			}
		}
		this.endtime=System.currentTimeMillis();////
		this.time=endtime-starttime;////
		return true;
	}
	public void qingling() {////
		this.starttime=this.endtime=System.currentTimeMillis();////
		this.time=0;////
	}
	
	public void restart() {
		level--;
		next();
		qingling();////
	}
	public void start() {
		next();
		this.starttime=System.currentTimeMillis();////
	}
	//��һ��
	public void last() {
		if(this.level>1)
			this.level--;
		else return;
		qingling();////
		toLevel(this.level);
	}
	
	public void next(){
		this.level++;
		qingling();////
		toLevel(this.level);
	}
	//��ȡ��ͼ��ά����
	public char[][]getMap(){
		return map;
	}
//ѡ��
	public void toLevel(int index) {
		this.level=index;
		this.map=MapUtil.getMap(index);
		this.map0=MapUtil.getMap(index);
		qingling();////
		clearstep();
	}
	//��ȡ��ǰ����
	public int getLevel() {
		return level;
	}
	//�����ƶ�
	public void moveDown() {
		System.out.println("==============��===========");
		int manX=0,manY=0;//С��ʵ������
		int oriX=0,oriY=0;//С�˵ĳ�ʼ����
		//�ҵ�С������
		for (int i = 0;  i < map.length; i++) {
			for (int j = 0; j < map[i].length; j++) {
				char c=map[i][j];
				int num=c-'0';
				if(num>=5 && num<=8) {
					//�ƶ�ǰС��Ϊ��ʼ����
					oriX=manX=j;
					oriY=manY=i;
				}
			}
		}
		//�ı�С�˷���
		manY++;
		if(map[manY][manX]=='1') {
			//С��ǰ���Ƿ���
			return;
		}else if(map[manY][manX]=='3' || map[manY][manX]=='9'){
			if(map[manY+1][manX]=='1' || map[manY+1][manX]=='3' || map[manY-1][manX]=='9') {
				//����ǰ���Ƿ���
				return;
			}else {
				if(map[manY+1][manX]=='4') {
					map[manY+1][manX]='9';
				}else {
					map[manY+1][manX]='3';
				}
			}
		}
		map[manY][manX]='5';
		//�ı�С��ԭ��������Ϊ�յ�
		//map[oriY][oriX]='2';
		map[oriY][oriX]=map0[oriY][oriX]=='4'||map0[oriY][oriX]=='9'?'4':'2';
		this.step++;
	}
	public void moveLeft() {
		System.out.println("==============��===========");
		int manX=0,manY=0;//С��ʵ������
		int oriX=0,oriY=0;//С�˵ĳ�ʼ����
		//�ҵ�С������
		for (int i = 0;  i < map.length; i++) {
			for (int j = 0; j < map[i].length; j++) {
				char c=map[i][j];
				int num=c-'0';
				if(num>=5 && num<=8) {
					//�ƶ�ǰС��Ϊ��ʼ����
					oriX=manX=j;
					oriY=manY=i;
				}
			}
		}
		//�ı�С�˷���
		manX--;
		
//		if(map[manY][manX]=='4')////
//			this.flag2=1;////
//		else this.flag2=0;////
		
		if(map[manY][manX]=='1') {
			//С��ǰ���Ƿ���
			return;
		}else if(map[manY][manX]=='3' || map[manY][manX]=='9'){
			if(map[manY][manX-1]=='1' || map[manY][manX-1]=='3' || map[manY][manX-1]=='9') {
				//����ǰ���Ƿ���
				return;
			}else {
				if(map[manY][manX-1]=='4') {
					map[manY][manX-1]='9';
				}else {
					map[manY][manX-1]='3';
				}
			}
		}
		map[manY][manX]='6';
		//�ı�С��ԭ��������Ϊ�յ�
		//map[oriY][oriX]='2';
		map[oriY][oriX]=map0[oriY][oriX]=='4'||map0[oriY][oriX]=='9'?'4':'2';
//		if(flag==1)////
//			map[oriY][oriX]='4';////
//		else map[oriY][oriX]='2';////
//		if(this.flag2==1)////
//			flag=1;////
//		else this.flag=0;////
		
		this.step++;
	}
	public void moveRight() {
		System.out.println("==============��===========");
		int manX=0,manY=0;//С��ʵ������
		int oriX=0,oriY=0;//С�˵ĳ�ʼ����
		//�ҵ�С������
		for (int i = 0;  i < map.length; i++) {
			for (int j = 0; j < map[i].length; j++) {
				char c=map[i][j];
				int num=c-'0';
				if(num>=5 && num<=8) {
					//�ƶ�ǰС��Ϊ��ʼ����
					oriX=manX=j;
					oriY=manY=i;
				}
			}
		}
		//�ı�С�˷���
		manX++;
		
//		if(map[manY][manX]=='4')////
//			this.flag2=1;////
//		else this.flag2=0;////
		
		if(map[manY][manX]=='1') {
			//С��ǰ���Ƿ���
			return;
		}else if(map[manY][manX]=='3' || map[manY][manX]=='9'){
			if(map[manY][manX+1]=='1' || map[manY][manX+1]=='3' || map[manY][manX+1]=='9') {
				//����ǰ���Ƿ���
				return;
			}else {
				if(map[manY][manX+1]=='4') {
					map[manY][manX+1]='9';
					//this.flag2=1;////
				}else {
					map[manY][manX+1]='3';
				}
			}
		}
		map[manY][manX]='7';
		//�ı�С��ԭ��������Ϊ�յ�
		//map[oriY][oriX]='2';
		map[oriY][oriX]=map0[oriY][oriX]=='4'||map0[oriY][oriX]=='9'?'4':'2';
//		if(flag==1)////
//			map[oriY][oriX]='4';////
//		else map[oriY][oriX]='2';////
//		if(this.flag2==1)////
//			flag=1;////
//		else this.flag=0;////
		this.step++;
	}
	//�����ƶ�С��
	public void moveUp() {
		System.out.println("==============��===========");
		int manX=0,manY=0;//С��ʵ������
		int oriX=0,oriY=0;//С�˵ĳ�ʼ����
		//�ҵ�С������
		for (int i = 0;  i < map.length; i++) {
			for (int j = 0; j < map[i].length; j++) {
				char c=map[i][j];
				int num=c-'0';
				if(num>=5 && num<=8) {
					//�ƶ�ǰС��Ϊ��ʼ����
					oriX=manX=j;
					oriY=manY=i;
				}
			}
		}
		//�ı�С�˷���
		manY--;
		if(map[manY][manX]=='1') {
			//С��ǰ���Ƿ���
			return;
		}else if(map[manY][manX]=='3' || map[manY][manX]=='9'){
			if(map[manY-1][manX]=='1' || map[manY-1][manX]=='3' || map[manY-1][manX]=='9') {
				//����ǰ���Ƿ���
				return;
			}else {
				if(map[manY-1][manX]=='4') {
					map[manY-1][manX]='9';
				}else {
					map[manY-1][manX]='3';
				}
			}
		}
		map[manY][manX]='8';
		//�ı�С��ԭ��������Ϊ�յ�
		//map[oriY][oriX]='2';
		map[oriY][oriX]=map0[oriY][oriX]=='4'||map0[oriY][oriX]=='9'?'4':'2';
		this.step++;
	}
	public int bushu() {
		return this.step;
	}
	public void clearstep() {
		//�������㲽��
		this.step=0;
	}
	
}
