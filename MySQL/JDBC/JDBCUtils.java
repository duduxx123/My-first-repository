package com.utils;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

//操作数据库的工具类
public class JDBCUtils {
    //获取数据库链接
    public static Connection getConnection() throws Exception{
        //1.提供另外3个链接的基本信息
        String ur1="jdbc:mysql://localhost:3306/dbtest1?useUnicode=true&characterEncoding=utf-8";
        String user="root";
        String password="duduxixi5656";
        //2.获取Driver实现类对象
        //MySQL自动注册和加载驱动,但建议保留加载驱动的代码
//        Class.forName("com.mysql.cj.jdbc.Driver");
//        Driver driver = (Driver) clazz.newInstance();
//        //注册驱动
//        DriverManager.registerDriver(driver);
        //3.获取链接
        Connection conn = DriverManager.getConnection(ur1, user, password);
        return conn;
    }
    //关闭链接
    public static void close(Connection conn, Statement ps){
        try{
            conn.close();
        }catch (Exception e){
            e.printStackTrace();
        }
        try {
            ps.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
