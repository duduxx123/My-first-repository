# bean的生命周期
```java
    @Test
    public void testOrders(){
//        ApplicationContext context
//                =new ClassPathXmlApplicationContext("bean4.xml");
        ClassPathXmlApplicationContext context
                =new ClassPathXmlApplicationContext("bean4.xml");
        System.out.println("第四步 获取创建的bean实例");
        Orders order=context.getBean("orders",Orders.class);
        System.out.println(order);
        //手动让bean实例销毁
//        ((ClassPathXmlApplicationContext)context).close();
        context.close();
    }
```
