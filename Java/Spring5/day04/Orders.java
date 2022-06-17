/*2、bean 生命周期

        1）通过构造器创建 bean 实例（无参数构造）

        2）为 bean 的属性设置值和对其他 bean 引用（调用 set 方法）

        3）调用 bean 的初始化的方法（需要进行配置初始化的方法）

        4）bean 可以使用了（对象获取到了）

        5）当容器关闭时候，调用 bean 的销毁的方法（需要进行配置销毁的方法）*/
/*4、bean 的后置处理器，bean 生命周期有七步 （正常生命周期为五步，而配置后置处理器后为七步）

        （1）通过构造器创建 bean 实例（无参数构造）

        （2）为 bean 的属性设置值和对其他 bean 引用（调用 set 方法）

        （3）把 bean 实例传递 bean 后置处理器的方法 postProcessBeforeInitialization

        （4）调用 bean 的初始化的方法（需要进行配置初始化的方法）

        （5）把 bean 实例传递 bean 后置处理器的方法 postProcessAfterInitialization

        （6）bean 可以使用了（对象获取到了）

        （7）当容器关闭时候，调用 bean 的销毁的方法（需要进行配置销毁的方法）*/
public class Orders {
    //无参数构造
    public Orders() {
        System.out.println("第一步 执行无参数构造创建 bean 实例");
    }
    private String oname;
    public void setOname(String oname) {
        this.oname = oname;
        System.out.println("第二步 调用 set 方法设置属性值");
    }
    //创建执行的初始化方法
    public void initNethod(){
        System.out.println("第三步 执行初始化的方法");
    }
    //创建执行的销毁的方法
    public void destroyMethod(){
        System.out.println("第五步 执行销毁的方法");
    }
}
