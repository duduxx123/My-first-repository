package com.prepared;

import com.utils.JDBCUtils;
import org.junit.Test;

import java.io.InputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.Properties;

public class PreparedStatementTest {
    //增
    @Test
    public void testInsert() throws Exception {
        InputStream is = PreparedStatementTest.class.getClassLoader().getResourceAsStream("jdbc.properties");
        Properties pros = new Properties();
        pros.load(is);
        String user=pros.getProperty("user");
        String password=pros.getProperty("password");
        String url=pros.getProperty("url");
        String driverClass=pros.getProperty("driverClass");
        Class.forName(driverClass);
        //获取数据库的连接
        Connection connection = DriverManager.getConnection(url,user,password);
        //获取PreparedStatement的实例 (或：预编译sql语句)
        String sql="insert into user(age,username,sex)values(?,?,?)";
        PreparedStatement ps = connection.prepareStatement(sql);
        //填充占位符
        ps.setInt(1,20);
        ps.setString(2,"xiaolei");
        ps.setString(3,"女");
        //执行sql语句
        ps.execute();
        Integer.valueOf("123");
    }
    //改
    @Test
    public void testUpdate() throws Exception {
        //1.获取链接
        Connection conn = JDBCUtils.getConnection();
        //2.预编译sql语句，返回PreparedStatement实例
        String sql="update user set username = ? where age = ?";
        PreparedStatement ps = conn.prepareStatement(sql);
        //3.填充占位符
        ps.setString(1,"jianghairui");
        ps.setInt(2,17);
        //4.执行
        ps.execute();
        //5.资源关闭
        JDBCUtils.close(conn,ps);
    }
    //通用的增删改操作
    public void update(String sql,Object ...args) {//sql中占位符的个数应该与可变形参的长度相同
        Connection conn=null;
        PreparedStatement ps=null;
        try {
            conn = JDBCUtils.getConnection();
            ps = conn.prepareStatement(sql);
            for (int i = 0; i < args.length; i++) {
                ps.setObject(i + 1, args[i]);
            }
            ps.execute();
        }catch (Exception e){
            e.printStackTrace();
        }finally {
            JDBCUtils.close(conn,ps);
        }
    }
    //数据库的查询操作
    @Test
    public void find(){
        Connection conn=null;
        PreparedStatement ps=null;
        String sql="select * from user where age > ?";
        try{
            conn=JDBCUtils.getConnection();
            ps=conn.prepareStatement(sql);
            ps.setInt(1,17);
            ResultSet resultSet = ps.executeQuery();//执行并返回(询完成后的)结果集
            //resultSet.next():判断结果集的下一条是否存在，如果有数据，返回true并指针下移
            while(resultSet.next()){
                //获取当前这条数据的各个字段值
                int age = resultSet.getInt(1);
                String name = resultSet.getString(2);
                String sex = resultSet.getString(3);
                System.out.println(age+" "+name+" "+sex);
                resultSet.close();
            }
        }catch (Exception e){
            e.printStackTrace();
        }finally {
            JDBCUtils.close(conn,ps);
        }
    }
    @Test
    public void employee(){
        String sql="select * from employee where id > ?";
        try {
            Connection conn = JDBCUtils.getConnection();
            PreparedStatement ps = conn.prepareStatement(sql);
            ps.setInt(1,1004);
            ResultSet rs = ps.executeQuery();
            System.out.println("id    name");
            while(rs.next()){
                int id=rs.getInt(1);
                Object name=rs.getObject(2);
                System.out.println(id+"  "+name);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}
