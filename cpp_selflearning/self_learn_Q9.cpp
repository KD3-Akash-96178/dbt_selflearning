#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    // Abstract method
    virtual void work() = 0; // pure virtual → makes Person abstract
};
class Student : public Person {
private:
    float marks;

public:
    Student(string n, int a, float m) : Person(n, a), marks(m) {}

    void study() {
        cout << name << " is studying." << endl;
    }

    void display() {
        Person::display();
        cout << "Marks: " << marks << endl;
    }

    void work() override { // implement abstract method
        cout << name << " is working as a Student." << endl;
    }
};
class Teacher : public Person {
private:
    double salary;

public:
    Teacher(string n, int a, double s) : Person(n, a), salary(s) {}

    void teach() {
        cout << name << " is teaching." << endl;
    }

    void display() {
        Person::display();
        cout << "Salary: " << salary << endl;
    }

    void work() override { // implement abstract method
        cout << name << " is working as a Teacher." << endl;
    }
};
int main() {
    Person* p; // base class pointer

    Student s("Alice", 20, 95.5);
    Teacher t("Bob", 40, 50000);

    // Using base class pointer to demonstrate run-time polymorphism
    p = &s;
    p->work(); // calls Student::work() → runtime polymorphism

    p = &t;
    p->work(); // calls Teacher::work() → runtime polymorphism

    cout << "----- Details -----" << endl;
    s.display();
    s.study();

    cout << endl;
    t.display();
    t.teach();

    return 0;
}
