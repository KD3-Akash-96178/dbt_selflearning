#include <iostream>
using namespace std;

class NegativeMarksException {
public:
    void message() {
        cout << "Error: Marks cannot be negative." << endl;
    }
};

class Student {
private:
    int marks;

public:
    Student() {
        marks = 0;
    }

    void setMarks(int m) {
        if (m < 0) {
            throw NegativeMarksException();
        }
        marks = m;
    }

    void display() {
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    Student s;

    try {
        s.setMarks(85);
        s.display();

        s.setMarks(-10);
    }
    catch (NegativeMarksException e) {
        e.message();
    }

    return 0;
}