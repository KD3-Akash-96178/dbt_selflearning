package sunbeam;

import java.util.*;

class Food {
 String type;

 Food(String type) {
     this.type = type;
 }
}

class Habitat {
 String environment;

 Habitat(String environment) {
     this.environment = environment;
 }
}

class Animal {
 String name;
 int age;

 Food food;
 Habitat habitat;

 Animal(String name, int age, Food food, Habitat habitat) {
     this.name = name;
     this.age = age;
     this.food = food;
     this.habitat = habitat;
 }

 void display() {
     System.out.println("Name: " + name + ", Age: " + age);
     System.out.println("Eats: " + food.type);
     System.out.println("Lives in: " + habitat.environment);
 }
}

class Lion extends Animal {
 Lion(String name, int age) {
     super(name, age, new Food("Meat"), new Habitat("Savannah"));
 }

 void roar() {
     System.out.println(name + " roars!");
 }
}

class Elephant extends Animal {
 Elephant(String name, int age) {
     super(name, age, new Food("Grass"), new Habitat("Forest"));
 }

 void trumpet() {
     System.out.println(name + " trumpets!");
 }
}

class Monkey extends Animal {
 Monkey(String name, int age) {
     super(name, age, new Food("Fruits"), new Habitat("Jungle"));
 }

 void jump() {
     System.out.println(name + " jumps!");
 }
}

class Zoo {
 List<Animal> animals = new ArrayList<>();

 void addAnimal(Animal a) {
     animals.add(a);
 }

 void showAnimals() {
     for (Animal a : animals) {
         a.display();
         System.out.println("-------------------");
     }
 }
}

public class SLQ3 {
 public static void main(String[] args) {

     Zoo zoo = new Zoo();

     Animal lion = new Lion("Simba", 5);
     Animal elephant = new Elephant("Dumbo", 10);
     Animal monkey = new Monkey("Chiku", 3);

     zoo.addAnimal(lion);
     zoo.addAnimal(elephant);
     zoo.addAnimal(monkey);

     zoo.showAnimals();

     ((Lion) lion).roar();
     ((Elephant) elephant).trumpet();
     ((Monkey) monkey).jump();
 }
}