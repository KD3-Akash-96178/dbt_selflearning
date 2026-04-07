package sunbeam;


class Student {
    int id;
    String name;

    Student() {
        id = 0;
        name = "Unknown";
        System.out.println("Default Constructor Called");
    }

    Student(int id, String name) {
        this.id = id;
        this.name = name;
        System.out.println("Parameterized Constructor Called");
    }

    Student(Student s) {
        this.id = s.id;
        this.name = new String(s.name); // Deep copy
        System.out.println("Deep Copy Constructor Called");
    }

    void display() {
        System.out.println("ID: " + id + ", Name: " + name);
    }
}


class Address {
    String city;

    Address(String city) {
        this.city = city;
    }
}

class ShallowStudent {
    int id;
    Address address;

    ShallowStudent(int id, Address address) {
        this.id = id;
        this.address = address;
    }

    ShallowStudent(ShallowStudent s) {
        this.id = s.id;
        this.address = s.address; // reference copied
    }

    void display() {
        System.out.println("ID: " + id + ", City: " + address.city);
    }
}


class DeepStudent {
    int id;
    Address address;

    DeepStudent(int id, Address address) {
        this.id = id;
        this.address = address;
    }

    // Deep Copy Constructor
    DeepStudent(DeepStudent s) {
        this.id = s.id;
        this.address = new Address(s.address.city);
    }

    void display() {
        System.out.println("ID: " + id + ", City: " + address.city);
    }
}


public class SLQ1 {
    public static void main(String[] args) {

        System.out.println("\n--- Multiple Constructors Demo ---");
        Student s1 = new Student();  
        s1.display();

        Student s2 = new Student(101, "Rahul"); 
        s2.display();

        Student s3 = new Student(s2);
        s3.display();

        s2.name = "Amit";

        System.out.println("\nAfter modifying s2:");
        s2.display();
        s3.display();

        System.out.println("\n--- Shallow Copy Demo ---");
        Address addr1 = new Address("Delhi");
        ShallowStudent ss1 = new ShallowStudent(201, addr1);
        ShallowStudent ss2 = new ShallowStudent(ss1);

        ss1.display();
        ss2.display();

        addr1.city = "Mumbai";

        System.out.println("\nAfter modifying address:");
        ss1.display();
        ss2.display();


        System.out.println("\n--- Deep Copy Demo ---");
        Address addr2 = new Address("Pune");
        DeepStudent ds1 = new DeepStudent(301, addr2);
        DeepStudent ds2 = new DeepStudent(ds1);

        ds1.display();
        ds2.display();

        addr2.city = "Chennai";

        System.out.println("\nAfter modifying address:");
        ds1.display();
        ds2.display();
    }
}
