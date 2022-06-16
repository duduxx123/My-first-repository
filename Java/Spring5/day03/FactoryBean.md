```java
public class MyBean implements FactoryBean<Course> {

    //定义返回bean
    @Override
    public Course getObject() throws Exception {
        Course course = new Course();
        course.setCname("abc");
        return course;
    }
}
```
```xml
<bean id="myBean" class="com.atguigu.spring5.factorybean.MyBean">
</bean>
```
```java
@Test
public void test3() {
 ApplicationContext context =
 new ClassPathXmlApplicationContext("bean3.xml");
 Course course = context.getBean("myBean", Course.class);//返回值类型可以不是定义的bean类型！
 System.out.println(course);
}
```
