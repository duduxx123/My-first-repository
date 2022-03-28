package com.zjd.pushbox.util;

import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;

public class MapUtil {
	public static char[][] getMap(int index){
		String path="com/zjd/pushbox/resource/map/"+index+".map";
		ClassLoader cl=MapUtil.class.getClassLoader();
		InputStream in=cl.getResourceAsStream(path);
		char[][] map=new char[20][20];
		for (int i = 0; i < map.length; i++) {
			for (int j = 0; j < map[i].length; j++) {
				try {
					char c=(char)in.read();
					if(c=='\r') {
						in.read();
						c=(char)in.read();
						}
					map[i][j]=c;
				} catch (IOException e) {
					e.printStackTrace();
				}		
			}
		}
		
		return map;
	}
	public static void main(String[] args) {
		char[][] map=getMap(18);
		for (int i = 0; i < map.length; i++) {
			for (int j = 0; j < map[i].length; j++) {
				System.out.print(map[i][j]+" ");
			}
			System.out.println();
		}
	}
	
	
}
