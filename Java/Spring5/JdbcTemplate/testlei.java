package com.atguigu.spring5.TestDemon;

import com.atguigu.spring5.entity.User;
import com.atguigu.spring5.service.BookService;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import java.util.Iterator;
import java.util.List;

public class testlei {
    @Test
    public void jdbctestadd(){
        ApplicationContext context=
                new ClassPathXmlApplicationContext("bean1.xml");
        BookService bookService = context.getBean("bookService", BookService.class);
        User user=new User();
        user.setUserId(19);
        user.setUsersex("女");
        user.setUsername("lll");
        bookService.addpeople(user);
    }
    @Test
    public void mysqlupdate(){
        ApplicationContext context=
                new ClassPathXmlApplicationContext("bean1.xml");
        BookService bookService = context.getBean("bookService", BookService.class);
        User user=new User();
        user.setUserId(20);
        user.setUsersex("女");
        user.setUsername("lll");
        bookService.updatepeople(user);
    }
    @Test
    public void jdbctestdele(){
        ApplicationContext context=
                new ClassPathXmlApplicationContext("bean1.xml");
        BookService bookService = context.getBean("bookService", BookService.class);
        bookService.delepeople(102);
    }
    @Test
    public void jdbcselect(){
        ApplicationContext context=
                new ClassPathXmlApplicationContext("bean1.xml");
        BookService bookService = context.getBean("bookService", BookService.class);
        bookService.selectuser(15);
    }
    @Test
    public void jdbcselectall(){
        ApplicationContext context=
                new ClassPathXmlApplicationContext("bean1.xml");
        BookService bookService = context.getBean("bookService", BookService.class);
        List<User> selecta = bookService.selecta();
        Iterator<User> iterator = selecta.iterator();
        while (iterator.hasNext())
            System.out.println(iterator.next());
    }
}
