import com.atguigu.spring5.dao.UserDao;

public interface UserDao {
    abstract public void update();
}

public class UserDaoImp implements UserDao{
    @Override
    public void update() {
        System.out.println("dao update");
    }
}

public class UserService {
    //创建UserDao类型属性，生成set方法
    private UserDao userDao;
    public void setUserDao(UserDao userDao) {
        this.userDao = userDao;
    }
    
    public void add(){
        System.out.println("service add.....");
        userDao.update();
    }
}
