package com.atguigu.spring5.dao;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Repository;

@Repository  //等价于 @Repository(value = "userDaoImpl1")
public class Dao implements Imp{
    @Value(value = "lmx")
    String name;
    @Override
    public void add(){
        System.out.println("dao add "+name);
    }
}
