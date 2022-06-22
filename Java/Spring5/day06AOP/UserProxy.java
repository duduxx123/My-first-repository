package spring5.AOPanno;

import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.*;
import org.springframework.stereotype.Component;

//2、创建增强类（编写增强逻辑）
//（1）在增强类里面，创建方法，让不同方法代表不同通知类型
//增强的类
@Component
@Aspect
public class UserProxy {
    //前置通知
    //before注解作为前置通知
    @Before(value = "execution(* spring5..User.add(..))")
    public void before(){
        System.out.println("before....");
    }
    @AfterReturning(value = "execution(* spring5..User.add(..))")
    public void ar(){//在方法返回结果之后执行
        System.out.println("AfterReturning....");
    }
    @AfterThrowing(value = "execution(* spring5..User.add(..))")
    public void at(){//异常通知  有异常才执行
        System.out.println("AfterThrowing....");
    }
    @After(value = "execution(* spring5..User.add(..))")
    public void after(){
        System.out.println("after....");
    }
    @Around(value = "execution(* spring5..User.add(..))")
    public void around(ProceedingJoinPoint proceedingJoinPoint) throws Throwable {//在增强的方法之前和之后都执行
        System.out.println("环绕之前");
        //被增强的方法
        proceedingJoinPoint.proceed();
        System.out.println("环绕之后");
    }
}
