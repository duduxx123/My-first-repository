package spring5.AOPanno;

import org.springframework.stereotype.Component;

//1、创建类，在类里面定义方法
@Component(value = "user")
public class User {
    public void add(){
        System.out.println("User add....");
    }
}
