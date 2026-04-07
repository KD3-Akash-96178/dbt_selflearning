package sunbeam;

abstract class Shape {
    abstract double area();
    abstract double volume();
}

abstract class TwoDShape extends Shape {
    @Override
    double volume() {
        return 0;
    }
}

class Circle extends TwoDShape {
    double radius;

    Circle(double radius) {
        this.radius = radius;
    }

    @Override
    double area() {
        return Math.PI * radius * radius;
    }
}

class Rectangle extends TwoDShape {
    double length, width;

    Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    double area() {
        return length * width;
    }
}

abstract class ThreeDShape extends Shape {
   
}

class Sphere extends ThreeDShape {
    double radius;

    Sphere(double radius) {
        this.radius = radius;
    }

    @Override
    double area() {
        return 4 * Math.PI * radius * radius;
    }

    @Override
    double volume() {
        return (4.0 / 3) * Math.PI * radius * radius * radius;
    }
}

class Cube extends ThreeDShape {
    double side;

    Cube(double side) {
        this.side = side;
    }

    @Override
    double area() {
        return 6 * side * side;
    }

    @Override
    double volume() {
        return side * side * side;
    }
}

public class SLQ2 {
    public static void main(String[] args) {

        Shape c = new Circle(5);
        Shape r = new Rectangle(4, 6);
        Shape s = new Sphere(3);
        Shape cu = new Cube(2);

        System.out.println("Circle Area: " + c.area());
        System.out.println("Circle Volume: " + c.volume());

        System.out.println("\nRectangle Area: " + r.area());
        System.out.println("Rectangle Volume: " + r.volume());

        System.out.println("\nSphere Surface Area: " + s.area());
        System.out.println("Sphere Volume: " + s.volume());

        System.out.println("\nCube Surface Area: " + cu.area());
        System.out.println("Cube Volume: " + cu.volume());
    }
}
