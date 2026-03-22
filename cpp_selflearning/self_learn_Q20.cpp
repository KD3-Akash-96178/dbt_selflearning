#include <iostream>
#include <memory>
using namespace std;

class Demo {
public:
    Demo() {
        cout << "Constructor called\n";
    }
    ~Demo() {
        cout << "Destructor called\n";
    }
    void show() {
        cout << "Demo object in use\n";
    }
};

int main() {

    unique_ptr<Demo> p1 = make_unique<Demo>();
    p1->show();

    unique_ptr<Demo> p2 = move(p1);

    if (!p1)
        cout << "p1 is now null after transfer\n";

    p2->show();


    shared_ptr<Demo> sp1 = make_shared<Demo>();
    shared_ptr<Demo> sp2 = sp1;

    cout << "Shared count: " << sp1.use_count() << endl;

    sp2->show();


    weak_ptr<Demo> wp = sp1;

    cout << "Weak pointer use_count: " << wp.use_count() << endl;

    if (auto temp = wp.lock()) {
        temp->show();
    } else {
        cout << "Object no longer exists\n";
    }

    return 0;
}