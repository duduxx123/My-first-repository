import java.util.*;

public class Stu {
    private String[] courses;
    private Set<String> set;
    private Map<String,String> map;
    private List<String> list;
    public void setList(List<String> list) {
        this.list = list;
    }

    public void setMap(Map<String, String> map) {
        this.map = map;
    }

    public void setSet(Set<String> set) {
        this.set = set;
    }
    
    public void setCourses(String[] courses) {
        this.courses = courses;
    }
    
    public void test(){
        System.out.println(Arrays.toString(courses));
        System.out.println(list);
        System.out.println(map);
        System.out.println(set);
    }
}
