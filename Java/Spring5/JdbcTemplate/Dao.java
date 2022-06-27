package com.atguigu.spring5.Dao;

import com.atguigu.spring5.entity.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public class Dao implements Imp{
    //添加的方法
    @Override
    public void add(User user) {
        //1.创建sql语句
        String sql="insert into user values(?,?,?)";
        //2.调用方法实现
        int update=jdbcTemplate.update(sql,user.getUserId(),user.getUsername(),user.getUsersex());//增删改都是用这个方法，只需要修改sql语句
        //下面的语句也有相同的效果
        //Object[] args = {user.getUsername(), user.getUserId(),user.getUsersex()};
        //int update = jdbcTemplate.update(sql, args);
        System.out.println(update);
    }
    //修改
    @Override
    public void update(User user){
        //1.创建sql语句
        String sql="update user set age=?,sex=? where username=?";
        //2.调用方法实现
        int update=jdbcTemplate.update(sql,user.getUserId(),user.getUsersex(),user.getUsername());//增删改都是用这个方法，只需要修改sql语句
        //下面的语句也有相同的效果
        //Object[] args = {user.getUsername(), user.getUserId(),user.getUsersex()};
        //int update = jdbcTemplate.update(sql, args);
        System.out.println(update);
    }
    @Override
    public void delete(int id) {
        //1.创建sql语句
        String sql="delete from user where age=?";
        //2.调用方法实现
        int update=jdbcTemplate.update(sql,id);//增删改都是用这个方法，只需要修改sql语句
        //下面的语句也有相同的效果
        //Object[] args = {user.getUsername(), user.getUserId(),user.getUsersex()};
        //int update = jdbcTemplate.update(sql, args);
        System.out.println(update);
    }

    //查询操作
    @Override
    public void select(int id) {
        String sql="select * from user where age=?";
        //调用方法
        User user = jdbcTemplate.queryForObject(sql, new BeanPropertyRowMapper<User>(User.class), id);
        System.out.println(user);
    }

    //返回集合的查询
    @Override
    public List<User> selectall(){
        String sql="select * from user";
        List<User> query = jdbcTemplate.query(sql, new BeanPropertyRowMapper<User>(User.class));
        return query;
    }
    
    @Autowired
    private JdbcTemplate jdbcTemplate;
}
