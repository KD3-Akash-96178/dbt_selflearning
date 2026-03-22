#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount(double b = 0) {
        balance = b;
    }

    void deposit(double amount) {
        if (amount < 0) {
            throw amount;
        }
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount < 0) {
            throw amount;
        }
        if (amount > balance) {
            throw string("Insufficient balance");
        }
        balance -= amount;
    }

    void display() {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc(1000);

    try {
        acc.deposit(500);
        acc.display();

        acc.deposit(-200);

        acc.withdraw(300);
        acc.display();

        acc.withdraw(2000);
    }
    catch (double amt) {
        cout << "Exception: Negative amount entered: " << amt << endl;
    }
    catch (string msg) {
        cout << "Exception: " << msg << endl;
    }

    return 0;
}