# 集合的注入
```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://www.springframework.org/schema/beans 
http://www.springframework.org/schema/beans/spring-beans.xsd">
    <bean id="stu" class="com.atguigu.spring5.collectionType.Stu">
<!--        数组类型属性注入-->
        <property name="courses">
            <array>
                <value>Java课程</value>
                <value>数据结构</value>
            </array>
        </property>
<!--        List类型属性注入-->
        <property name="list">
            <list>
                <value>lmx</value>
                <value>jhr</value>
            </list>
        </property>
<!--        Map类型属性注入-->
        <property name="map">
            <map>
                <entry key="JAVA" value="java"/>
                <entry key="PHP" value="php"/>
            </map>
        </property>
<!--        Set类型属性注入-->
        <property name="set">
            <set>
                <value>MuSQL</value>
                <value>Oracle</value>
            </set>
        </property>
    </bean>
</beans>
```
