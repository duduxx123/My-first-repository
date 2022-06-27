package com.atguigu.spring5.service;

import com.atguigu.spring5.Dao.Dao;
import com.atguigu.spring5.entity.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class BookService {
    @Autowired
    private Dao dao;
    
    //添加的方法
    public void addpeople(User user){
        dao.add(user);
    }
    //修改的方法
    public void updatepeople(User user){
        dao.update(user);
    }
    //删除的方法
    public void delepeople(int id){
        dao.delete(id);
    }
    //查询的方法
    public void selectuser(int id){
        dao.select(id);
    }
    //查询返回集合
    public List<User> selecta(){
        return dao.selectall();
    }
}
