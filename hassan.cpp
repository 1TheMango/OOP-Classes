

#include <iostream>
using namespace std;

class polynomial {
private:
    int a;
    int b;
public:
    polynomial(): a(0), b(0) {};
    polynomial(int as, int bs): a(as), b(bs) {};
    ~polynomial() {};

    // Copy constructor
    polynomial(const polynomial& other): a(other.a), b(other.b) {};

    // Operator+ return by value
    polynomial operator+(const polynomial& rhs) {
        cout << "operator+ called (return by value)\n";
        return polynomial(a + rhs.a, b + rhs.b);
    }

    // operator= returning by reference
    polynomial& operator=(const polynomial& rhs) {
        cout << "operator= returning by reference\n";
        a = rhs.a;
        b = rhs.b;
        return *this;
    }


    // returning by reference
    polynomial& operator++() {
        cout << "returning by reference\n";
        ++a; ++b;
        return *this;
    }
    polynomial operator++() { // return by value creates a new copy of the chaining result, probably doesnt work with multiple chainings
        cout << "returning by value\n"; 
        ++a; ++b;
        return polynomial(a, b)
    }


    // operator+= returning by reference
    polynomial& operator+=(const polynomial& rhs) {
        cout << "operator+= returning by reference\n";
        a += rhs.a;
        b += rhs.b;
        return *this;
    }

    // operator+= returning by value // creates a new copy but doesnt refrence the original address
    polynomial operator+=(const polynomial& rhs) {
        cout << "operator+= returning by value\n";
        a += rhs.a;
        b += rhs.b;
        return polynomial(a, b)
    }


    void print() {
        cout << "polynomial: " << a << "x + " << b << "\n";
    }
};

int main() {
    polynomial A;
    polynomial B(5, 7);
    polynomial C;

    C = A + B + B; // This works fine, operator+ returns by value so chaining is fine
    C.print();

    A = B = C; // Chain assignment

    A.print();
    B.print();

    ++(++A);

    A.print();
    (A += B) += C;

    A.print();

    return 0;
}
