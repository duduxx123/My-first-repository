# AOP操作
AOP 操作（AspectJ 注解）
```java
    @Test
    public void AOPTest(){
        ApplicationContext context
                =new ClassPathXmlApplicationContext("bean3.xml");
        User user = context.getBean("user", User.class);
        user.add();
    }
```
    
