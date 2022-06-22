package spring5.AOPanno;

import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.springframework.core.annotation.Order;
import org.springframework.stereotype.Component;

//有多个增强类对同一个方法进行增强，设置增强类优先级
@Component
@Aspect
public class PersonProxy {
    @Before(value = "execution(* spring5..User.add(..))")
    @Order(1)//（1）在增强类上面添加注解 @Order(数字类型值)，数字类型值越小优先级越高
    public void personbefore(){
        System.out.println("Person before....");
    }
}
