# 使用DBeaver测试
``` SQL
show databases;
use dbtest1;
select * from dbtest1.employee;
 #MySQL DBever
show tables;
insert into employee value(1028,'蒋海瑞');
#最基本的select语句:select 字段1，字段2... from 表名
select 1+1,3*2
from dual; #dual是伪表，不加from dual也行
#列的别名:
#as可以省略 别名建议使用双引号包住，不使用不能写空格
select name as "姓名" from employee;
select id as "学号",name  from employee;
#distinct:去除重复行(不真正在表中删除)
select distinct * from dbtest1.employee;
#空值NULL运算后就结果都为NULL
select  8*null,null+1;
delete from dbtest1.employee where id=1028;#删除id为1028的所有数据
#显示表的结构
describe employee;#显示表中字段的详细信息
desc employee;#效果同上
#过滤条件 使用where
select * from employee where id=1024;
#使id扩大12倍并使用别名为ID×12
select id*12 as "ID×12",name as "姓名" from employee e ;
#查询id大于1050的所有数据
select * from employee e where id>=1050;
# <=>安全等于运算符，可以对NULL进行判断，在两个操作数均为NULL时返回0,一个为NULL返回1
#筛选id在1000到1050之间的数据,包含边界(between前加not表示不在...之间且不包含边界)
select * 
from employee 
where id /*not*/between 1000 and 1050;
#id >= 1000 or id <= 1050
```
