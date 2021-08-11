abstract class Person{
    
    private int id;
    private String name;
    
    public int getId(){
        return this.id;
    }
    
    public String getName(){
        return this.name;
    }
    
    Person(int id,String name){
        this.id = id;
        this.name = name;
    }
}

class Student extends Person{
    int marks;
    Student(int id,String name,int marks){
        super(id, name);
        this.marks = marks;
    }
}
public class test{
    public static void main(String[] args) {
        Student s1 = new Student(1,"asdsa",2);
        System.out.println(s1.getId()+" "+s1.getName()+" "+s1.marks);
    }
}