package com.atguigu.spring5.testdemon;

import com.atguigu.spring5.User;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class test {
    @Test
    public void test(){
        ApplicationContext context
                =new ClassPathXmlApplicationContext("demon.xml");
        User user = context.getBean("user", User.class);
        System.out.println(user);
        user.add();
    }
}
