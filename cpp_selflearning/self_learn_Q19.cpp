#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
    list<int> l;

    for (int i = 0; i < 10; i++) {
        l.push_back(rand() % 100);
    }

    cout << "List in reverse order:\n";
    for (list<int>::reverse_iterator rit = l.rbegin(); rit != l.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        *it += 5;
    }

    cout << "List using const iterator:\n";
    for (list<int>::const_iterator cit = l.begin(); cit != l.end(); ++cit) {
        cout << *cit << " ";
    }
    cout << endl;

    l.sort();

    cout << "Modified sorted list:\n";
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}