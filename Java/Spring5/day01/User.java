package com.atguigu.spring5;

public class User {
    private String name;
    private int num;
    public void add(){
        System.out.println("add......");
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setNum(int num) {
        this.num = num;
    }

    public void prin() {
        System.out.println(name);
        System.out.println(num);
    }

    public User(String name, int num) {
        this.name = name;
        this.num = num;
    }
}
