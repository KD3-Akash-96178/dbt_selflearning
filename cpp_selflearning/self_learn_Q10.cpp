#include<iostream>
//10. Implement a `Matrix` class and overload `+`, `-`, and `*` operators. 
#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    int rows, cols;
    vector<vector<int>> data;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data.resize(rows, vector<int>(cols, 0));
    }

    void input() {
        cout << "Enter elements (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrix dimensions must match for addition.");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrix dimensions must match for subtraction.");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) {
        if (cols != other.rows) {
            throw invalid_argument("Invalid dimensions for multiplication.");
        }

        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    int r1, c1, r2, c2;

    cout << "Enter rows and cols of Matrix A: ";
    cin >> r1 >> c1;

    cout << "Enter rows and cols of Matrix B: ";
    cin >> r2 >> c2;

    Matrix A(r1, c1), B(r2, c2);

    cout << "Matrix A:\n";
    A.input();

    cout << "Matrix B:\n";
    B.input();

    try {
        cout << "\nAddition:\n";
        Matrix sum = A + B;
        sum.display();

        cout << "\nSubtraction:\n";
        Matrix diff = A - B;
        diff.display();

        cout << "\nMultiplication:\n";
        Matrix prod = A * B;
        prod.display();
    }
    catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}