#include <iostream>
using namespace std;

template <class T>
class Array {
private:
    T* arr;
    int size;

public:
    Array(int s) {
        size = s;
        arr = new T[size];
    }

    ~Array() {
        delete[] arr;
    }

    Array(const Array& other) {
        size = other.size;
        arr = new T[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] arr;
            size = other.size;
            arr = new T[size];
            for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw "Index out of bounds";
        }
        return arr[index];
    }

    int getSize() const {
        return size;
    }

    void input() {
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    void display() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Student {
private:
    int roll;
public:
    Student(int r = 0) {
        roll = r;
    }

    friend istream& operator>>(istream& in, Student& s) {
        in >> s.roll;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Student& s) {
        out << s.roll;
        return out;
    }
};

int main() {
    Array<int> a1(5);
    cout << "Enter integers:\n";
    a1.input();
    a1.display();

    Array<Student> a2(3);
    cout << "Enter student rolls:\n";
    a2.input();
    a2.display();

    try {
        cout << "Element at index 2: " << a1[2] << endl;
    }
    catch (const char* msg) {
        cout << msg << endl;
    }

    return 0;
}