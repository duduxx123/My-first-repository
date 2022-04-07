package com.zjd.pushbox.core;

import com.zjd.pushbox.util.MapUtil;


//游戏核心业务类
public class PushBoxGame {
	
	private int level;
	int step=0;//统计步数
//	int flag=0;//改小人刷掉目的地的BUG
//	int flag2=0;//同上
	long starttime;//计时
	public long time;//同上
	long endtime;//同上
	private char[][]map0;
	private char[][]map;
	
	//判断当前关卡是否结束
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
	//上一关
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
	//获取地图二维数组
	public char[][]getMap(){
		return map;
	}
//选关
	public void toLevel(int index) {
		this.level=index;
		this.map=MapUtil.getMap(index);
		this.map0=MapUtil.getMap(index);
		qingling();////
		clearstep();
	}
	//获取当前关数
	public int getLevel() {
		return level;
	}
	//向下移动
	public void moveDown() {
		System.out.println("==============下===========");
		int manX=0,manY=0;//小人实际坐标
		int oriX=0,oriY=0;//小人的初始坐标
		//找到小人坐标
		for (int i = 0;  i < map.length; i++) {
			for (int j = 0; j < map[i].length; j++) {
				char c=map[i][j];
				int num=c-'0';
				if(num>=5 && num<=8) {
					//移动前小人为初始坐标
					oriX=manX=j;
					oriY=manY=i;
				}
			}
		}
		//改变小人方向
		manY++;
		if(map[manY][manX]=='1') {
			//小人前面是房子
			return;
		}else if(map[manY][manX]=='3' || map[manY][manX]=='9'){
			if(map[manY+1][manX]=='1' || map[manY+1][manX]=='3' || map[manY-1][manX]=='9') {
				//箱子前面是房子
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
		//改变小人原来的坐标为空地
		//map[oriY][oriX]='2';
		map[oriY][oriX]=map0[oriY][oriX]=='4'||map0[oriY][oriX]=='9'?'4':'2';
		this.step++;
	}
	public void moveLeft() {
		System.out.println("==============左===========");
		int manX=0,manY=0;//小人实际坐标
		int oriX=0,oriY=0;//小人的初始坐标
		//找到小人坐标
		for (int i = 0;  i < map.length; i++) {
			for (int j = 0; j < map[i].length; j++) {
				char c=map[i][j];
				int num=c-'0';
				if(num>=5 && num<=8) {
					//移动前小人为初始坐标
					oriX=manX=j;
					oriY=manY=i;
				}
			}
		}
		//改变小人方向
		manX--;
		
//		if(map[manY][manX]=='4')////
//			this.flag2=1;////
//		else this.flag2=0;////
		
		if(map[manY][manX]=='1') {
			//小人前面是房子
			return;
		}else if(map[manY][manX]=='3' || map[manY][manX]=='9'){
			if(map[manY][manX-1]=='1' || map[manY][manX-1]=='3' || map[manY][manX-1]=='9') {
				//箱子前面是房子
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
		//改变小人原来的坐标为空地
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
		System.out.println("==============右===========");
		int manX=0,manY=0;//小人实际坐标
		int oriX=0,oriY=0;//小人的初始坐标
		//找到小人坐标
		for (int i = 0;  i < map.length; i++) {
			for (int j = 0; j < map[i].length; j++) {
				char c=map[i][j];
				int num=c-'0';
				if(num>=5 && num<=8) {
					//移动前小人为初始坐标
					oriX=manX=j;
					oriY=manY=i;
				}
			}
		}
		//改变小人方向
		manX++;
		
//		if(map[manY][manX]=='4')////
//			this.flag2=1;////
//		else this.flag2=0;////
		
		if(map[manY][manX]=='1') {
			//小人前面是房子
			return;
		}else if(map[manY][manX]=='3' || map[manY][manX]=='9'){
			if(map[manY][manX+1]=='1' || map[manY][manX+1]=='3' || map[manY][manX+1]=='9') {
				//箱子前面是房子
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
		//改变小人原来的坐标为空地
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
	//向上移动小人
	public void moveUp() {
		System.out.println("==============上===========");
		int manX=0,manY=0;//小人实际坐标
		int oriX=0,oriY=0;//小人的初始坐标
		//找到小人坐标
		for (int i = 0;  i < map.length; i++) {
			for (int j = 0; j < map[i].length; j++) {
				char c=map[i][j];
				int num=c-'0';
				if(num>=5 && num<=8) {
					//移动前小人为初始坐标
					oriX=manX=j;
					oriY=manY=i;
				}
			}
		}
		//改变小人方向
		manY--;
		if(map[manY][manX]=='1') {
			//小人前面是房子
			return;
		}else if(map[manY][manX]=='3' || map[manY][manX]=='9'){
			if(map[manY-1][manX]=='1' || map[manY-1][manX]=='3' || map[manY-1][manX]=='9') {
				//箱子前面是房子
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
		//改变小人原来的坐标为空地
		//map[oriY][oriX]='2';
		map[oriY][oriX]=map0[oriY][oriX]=='4'||map0[oriY][oriX]=='9'?'4':'2';
		this.step++;
	}
	public int bushu() {
		return this.step;
	}
	public void clearstep() {
		//用于清零步数
		this.step=0;
	}
	
}
