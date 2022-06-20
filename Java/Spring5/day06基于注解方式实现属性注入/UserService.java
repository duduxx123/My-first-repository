package com.atguigu.spring5.Service;

import com.atguigu.spring5.dao.Dao;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

//在注解里面 value 属性值可以省略不写，
//默认值是类名称，首字母小写
//UserService --> userService
@Component(value = "userService") //注解等同于XML配置文件：<bean id="userService" class=".."/>
public class UserService {
    @Value(value="jhr")//普通类型的注解注入
    private String name;
    @Autowired
    private Dao userdao;
    public void add() {
        System.out.println("service add......."+name);
        userdao.add();
    }
}
