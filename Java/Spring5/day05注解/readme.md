# 注解
``` java
    public void test(){
        ApplicationContext context
                =new ClassPathXmlApplicationContext("bean1.xml");
        UserService userService = context.getBean("userService", UserService.class);
        System.out.println(userService);
        userService.add();
    }
```
