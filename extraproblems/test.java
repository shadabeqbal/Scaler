abstract class Switch{
    final int on;
    abstract void checkstatus(); 
}

public class test extends Switch{
    
    void checkstatus(){
        if(this.on == 1)
            System.out.println("Bulb is Glowing");
        else
            System.out.prinln("Bulb is Off");
    }
    public static void main(String[] args) {
        Switch obj = new Switch();
        obj.checkstatus();
    }
}
