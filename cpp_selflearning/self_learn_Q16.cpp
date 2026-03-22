#include <iostream>
using namespace std;

class Student {
public:
    void display() {
        cout << "Student details displayed" << endl;
    }
};

class SmartPointer {
private:
    Student* ptr;

public:
    SmartPointer(Student* p) {
        ptr = p;
    }

    ~SmartPointer() {
        delete ptr;
        cout << "Memory freed automatically" << endl;
    }

    Student* operator->() {
        return ptr;
    }

    Student& operator*() {
        return *ptr;
    }
};

int main() {
    try {
        SmartPointer s(new Student);

        s->display();

        throw 1;
    }
    catch (...) {
        cout << "invalid input" << endl;
    }

    return 0;
}