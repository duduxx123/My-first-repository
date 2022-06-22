# AOP操作
## AOP（术语）
a）连接点：类里面哪些方法可以被增强，这些方法称为连接点

b）切入点：实际被真正增强的方法称为切入点

c）通知（增强）：实际增强的逻辑部分称为通知，且分为以下五种类型：

1）前置通知 2）后置通知 3）环绕通知 4）异常通知 5）最终通知

d）切面：把通知应用到切入点过程
## AOP 操作（AspectJ 注解）
```java
    @Test
    public void AOPTest(){
        ApplicationContext context
                =new ClassPathXmlApplicationContext("bean3.xml");
        User user = context.getBean("user", User.class);
        user.add();
    }
```
    
## 有多个增强类对同一个方法进行增强，设置增强类优先级
```java
//（1）在增强类上面添加注解 @Order(数字类型值)，数字类型值越小优先级越高
@Component
@Aspect
@Order(1)
public class PersonProxy{ }
```
