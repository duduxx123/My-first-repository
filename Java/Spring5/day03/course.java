public class course {
    private String cname;

    public void setCname(String cname) {
        this.cname = cname;
    }

    @Override
    public String toString() {
        return "course{" +
                "cname='" + cname + '\'' +
                '}';
    }
}
