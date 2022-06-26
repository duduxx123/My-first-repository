# JdbcTemplate
## 1、JdbcTemplate概念及使用
​ a）Spring 框架对 JDBC 进行封装，使用 JdbcTemplate 方便实现对数据库操作

​ b）引入相关 jar 包

​ c）在 spring 配置文件配置数据库连接池

```xml
<bean id="dataSource" class="com.alibaba.druid.pool.DruidDataSource"
 destroy-method="close">
 <property name="url" value="jdbc:mysql:///test" />
 <property name="username" value="root" />
 <property name="password" value="root" />
 <property name="driverClassName" value="com.mysql.jdbc.Driver" />
</bean>
```
​ d）配置 JdbcTemplate 对象，注入 DataSource
```java
<!-- JdbcTemplate 对象 -->
<bean id="jdbcTemplate" class="org.springframework.jdbc.core.JdbcTemplate">
 <!--注入 dataSource-->
 <property name="dataSource" ref="dataSource"></property><!--set方式注入-->
</bean>
```
​ e）创建 service 类，创建 dao 类，在 dao 注入 jdbcTemplate 对象
```xml
<!-- 组件扫描 -->
<context:component-scan base-package="com.atguigu"></context:component-scan>
```
```java
@Service
public class BookService {
 //注入 dao
 @Autowired
 private BookDao bookDao;
}

@Repository
public class BookDaoImpl implements BookDao {
 //注入 JdbcTemplate
 @Autowired
 private JdbcTemplate jdbcTemplate;
}
```
## 2、JdbcTemplate 操作数据库（添加）
​ a）对应数据库创建实体类

​ b）创建service和dao

​ （1）在 dao 进行数据库添加操作

​ （2）调用 JdbcTemplate 对象里面 update 方法实现添加操作

```java
@Repository
public class BookDaoImpl implements BookDao {
 //注入 JdbcTemplate
 @Autowired
 private JdbcTemplate jdbcTemplate;
 //添加的方法
 @Override
 public void add(Book book) {
 //1 创建 sql 语句
 String sql = "insert into t_book values(?,?,?)";
 //2 调用方法实现
 Object[] args = {book.getUserId(), book.getUsername(),book.getUstatus()};
 int update = jdbcTemplate.update(sql,args);
 System.out.println(update);
 }
}
```
3、JdbcTemplate 操作数据库（修改和删除）
```java
//1、修改
@Override
public void updateBook(Book book) {
 String sql = "update t_book set username=?,ustatus=? where user_id=?";
 Object[] args = {book.getUsername(), book.getUstatus(),book.getUserId()};
 int update = jdbcTemplate.update(sql, args);
 System.out.println(update);
}
//2、删除
@Override
public void delete(String id) {
 String sql = "delete from t_book where user_id=?";
 int update = jdbcTemplate.update(sql, id);
 System.out.println(update);
}
//使用JdbcTemplate 模板所实现的 “增删改” 都是调用了同一个 “update” 方法
```
