public class emm {
    private dep dept;
    public void setDept(dep dept) {
        this.dept = dept;
    }
    @Override
    public String toString() {
        return "emm{" +
                "dept=" + dept +
                '}';
    }
    public void test(){
        System.out.println(dept);
    }
}
