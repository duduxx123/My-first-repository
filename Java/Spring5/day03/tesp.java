import com.atguigu.spring5.collectionType.Stu;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;


public class tesp {
    @Test
    public void test(){
        ApplicationContext context
                =new ClassPathXmlApplicationContext("bean1.xml");
        Stu stu=context.getBean("stu",Stu.class);
        stu.test();
    }
}
