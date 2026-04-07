
import java.util.Arrays;
import java.util.Comparator;

class Student {
    private int roll;
    private String name;
    private String city;
    private double marks;

    public Student(int roll, String name, String city, double marks) {
        this.roll = roll;
        this.name = name;
        this.city = city;
        this.marks = marks;
    }

    public int getRoll() { return roll; }
    public String getName() { return name; }
    public String getCity() { return city; }
    public double getMarks() { return marks; }

    @Override
    public String toString() {
        return "Student{" +
                "roll=" + roll +
                ", name='" + name + '\'' +
                ", city='" + city + '\'' +
                ", marks=" + marks +
                '}';
    }
}

public class SLQ13 {
    public static void main(String[] args) {

        Student[] students = {
                new Student(101, "Alice", "Delhi", 85.5),
                new Student(102, "Bob", "Mumbai", 92.0),
                new Student(103, "Charlie", "Delhi", 85.5),
                new Student(104, "David", "Mumbai", 88.0),
                new Student(105, "Eve", "Delhi", 95.0)
        };

        Arrays.sort(students, Comparator
                .comparing(Student::getCity, Comparator.reverseOrder())  
                .thenComparing(Student::getMarks, Comparator.reverseOrder())  
                .thenComparing(Student::getName) 
        );

        System.out.println("Sorted Students:");
        for (Student s : students) {
            System.out.println(s);
        }
    }
}
