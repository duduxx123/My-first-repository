import java.util.*;

/*
* 集合框架的概述:
* Java集合可分为Collection和Map(映射)两种体系
*   Collection接口:单列数据，定义了存储一组对象的方法的集合
*   List:元素有序，可重复的合集    (动态数组)
*        |----ArrayList：作为List接口的主要实现类，线程不安全的，效率高;底层采用Object[] elementData数组存储
*            |----建议开发中使用带参构造器: ArrayList list = new ArrayList(int capacity);capacity为容量
         |----LinkedList：对于频繁的插入删除操作，使用此类效率比ArrayList效率高底层采用双向链表存储
         |----Vector：作为List的古老实现类，线程安全的，效率低;底层采用Object[]数组存储。
*   Set:元素无序(不是随机)，不可重复的集合(没有声明新方法，只能使用Collection接口声明的方法)
*       |----HashSet：作为Set接口主要实现类;线程不安全;可以存null值
           		|----LinkedHashSet：作为HashSet的子类;遍历其内部数据时，可以按照添加顺序遍历;对于频繁的遍历操作，LinkedHashSet效率高于HashSet.
           |----TreeSet：可以按照添加对象的指定属性，进行排序。
*   Map接口:
*   双列数据，保存具有映射关系"key-value对"的集合
*       /----HashMap,LinkedHashMap,TreeMap,HashTable，Properties
* |----HashMap:作为Map的主要实现类；线程不安全的，效率高；存储null的key和value
          |----LinkedHashMap:保证在遍历map元素时，可以照添加的顺序实现遍历。
                    原因：在原的HashMap底层结构基础上，添加了一对指针，指向前一个和后一个元素。
                    对于频繁的遍历操作，此类执行效率高于HashMap。
     |----TreeMap:保证照添加的key-value对进行排序，实现排序遍历。此时考虑key的自然排序或定制排序
                      底层使用红黑树
     |----Hashtable:作为古老的实现类；线程安全的，效率低；不能存储null的key和value
          |----Properties:常用来处理配置文件。key和value都是String类型
* */
public class CollectionTest {
    public static void main(String[] args) {
        Collection coll=new ArrayList();
        //add(Object e)将元素e添加到集合coll中
        coll.add("LMX");
        coll.add("JHR");
        coll.add(123);
        coll.add(new Date());
        //size()获取添加元素的个数
        System.out.println("元素个数为:"+coll.size());//4
        System.out.println(coll);//输出集合coll中的全部元素，等同于ArrayList中重写的coll.toString()
        Collection coll1=new ArrayList();
        coll1.add(new String("ZJD"));
        coll1.add(456);
        coll.addAll(coll1);//将coll1中的全部元素添加到当前集合中
        System.out.println("元素个数为:"+coll.size());//6
        System.out.println(coll.toString());
        //contains(Object obj)判断当前集合中是否包含obj对象
        System.out.println(coll.contains(new String("ZJD")));//输出为true，说明contains()判断的是数值而不是地址,调用的是String中被重写的equals()方法
        List CO= Arrays.asList("LMX","666","ZJD");//使用多态性建立一个新集合
        //containsAll(CO)判断CO中的所有元素是否都在当前集合中
        System.out.println(coll.containsAll(CO));
        //remove(Object o)移除当前集合中的o元素
        coll.remove(456);
        coll.remove(123);
        System.out.println(coll);
        //删除coll1中和coll相等的元素
        //coll.removeAll(coll1);
        //求coll1和CO的交集，并将结果放在coll1中
        coll1.retainAll(CO);
        System.out.println(coll1);
        //equails()返回两个集合是否相等
        System.out.println(coll.equals(coll));
        //hashCode()获取当前集合的哈希值
        System.out.println(coll.hashCode());
//        toArray() 将集合转化为Object类型的数组
        Object[] arr = coll.toArray();
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+" ");
        }
        //clear()清空集合中的元素
        coll.clear();
        //isEmpty()判断当前集合是否为空
        System.out.println(coll.isEmpty());//true
        //数组到集合的转换
        List<String> list = Arrays.asList(new String[]{"AA", "BB", "CC"});
        System.out.println(list);
        List arr1 = Arrays.asList(123,456);
        System.out.println(arr1.toString());
        //iterator()返回Iterator接口的实例
        //JDK5.0新增foreach循环，用来遍历集合和数组 for(集合元素类型 局部变量 : 集合对象)
        System.out.print("增强for循环:");
        for(Object obj:list){
            System.out.print(obj+" ");
        }
        System.out.println();
        //使用增强for循环遍历数组:for(数组的类型 局部变量 : 数组名)
        char[] arr2=new char[]{'j','h','r'};
        for(char c:arr2)
            System.out.print(c);
        //（注意）修改迭代器的值无法改变本身的值
        System.out.println("\n**********************************");
        //建议开发中使用带参构造器: ArrayList list = new ArrayList(int capacity);capacity为容量
        ArrayList list1 = new ArrayList();
        list1.add(123);
        list1.add("xiaolei");
        list1.add("xiaorui");
        list1.add(456);
        list1.add(123);//List可以存放重复数据
        list1.add(2,"ZJD");//在index位置插入element元素
        System.out.println(list1);
        System.out.println(list1.indexOf("xiaorui"));//indexOf() 返回元素在集合中首次出现的位置，否则返回-1
        //lastIndexOf() 返回元素最后一次出现的位置
        System.out.println("SET TEST**************************");
        HashSet set = new HashSet();
        set.add("dudu");
        set.add("xixi");
        set.add("HLQ");
        set.add("YZY");
        set.add(new dudu("hahaha",18));
        Iterator iterator=set.iterator();//迭代器
        while (iterator.hasNext())
            System.out.print(iterator.next()+" ");//通过数据元素的哈希值决定位置
        Set link=new LinkedHashSet();//无序存放，但按照添加的顺序输出（每个数据维护了两个引用，记录此数据前一个数据和后一个数据，适用于频繁的遍历操作）
        link.add("linhao");
        link.add("dudule");
        link.add(789);
        System.out.println("\n"+link);
        //向TreeSet中添加的对象，要求是相同类型的对象
        TreeSet treeSet = new TreeSet();//TreeSet底层红黑树
        treeSet.add(14);
        treeSet.add(-14);
        treeSet.add(75);
        treeSet.add(100);
        iterator=treeSet.iterator();
        while(iterator.hasNext())
            System.out.print(iterator.next()+" ");//可以按照添加对象的指定属性，进行排序
        treeSet.clear();
        /*treeSet.add(new dudu("xixi",18));
        treeSet.add(new dudu("dudu",20));
        iterator=treeSet.iterator();
        while(iterator.hasNext())
            System.out.print("\n"+iterator.next()+" ");
         */
        
    }   
}
class dudu {
    private String xixi;
    private int age;

    public dudu(String xixi, int age) {
        this.xixi = xixi;
        this.age = age;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof dudu)) return false;
        dudu dudu = (dudu) o;
        return age == dudu.age && Objects.equals(xixi, dudu.xixi);
    }

    @Override
    public int hashCode() {
        return Objects.hash(xixi, age);
    }
}
