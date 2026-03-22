#include <iostream>
#include <fstream>
using namespace std;

class Student {
private:
    int roll;
    char name[50];
    float marks;

public:
    void input() {
        cout << "Enter Roll: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "Roll: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }

    void saveToFile() {
        ofstream fout("student.dat", ios::binary);
        fout.write((char*)this, sizeof(*this));
        fout.close();
    }

    void loadFromFile() {
        ifstream fin("student.dat", ios::binary);
        fin.read((char*)this, sizeof(*this));
        fin.close();
    }
};

int main() {
    Student s1, s2;

    cout << "Enter Student Details:\n";
    s1.input();

    s1.saveToFile();

    cout << "\nData saved to file.\n";

    s2.loadFromFile();

    cout << "\nLoaded Student Details:\n";
    s2.display();

    return 0;
}