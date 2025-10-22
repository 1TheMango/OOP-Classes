// We'll compare:
// LibraryRef , operators return by reference (conventional)
// LibraryVal , operators return by value (non-reference)

#include <iostream>
using namespace std;

class LibraryRef {
    int books;
    static int total; // total books in all libraries
public:
    LibraryRef(int n = 0) : books(n) { total += n; }

    LibraryRef& operator=(const LibraryRef& rhs) {
        total -= books;
        books = rhs.books;
        total += books;
        cout << "LibraryRef::operator= called\n";
        return *this; // return reference allows chaining
    }

    LibraryRef& operator+=(int n) {
        books += n;
        total += n;
        cout << "LibraryRef::operator+= added " << n << " books\n";
        return *this; 
    }

    LibraryRef& operator++() {
        ++books;
        ++total;
        cout << "LibraryRef::operator++ prefix increment\n";
        return *this;
    }

    void show() const { cout << "Library has " << books << " books" << endl; }
    static void showTotal() { cout << "Total books = " << total << endl; }
};

int LibraryRef::total = 0;


class LibraryVal {
    int books;
    static int total;
public:
    LibraryVal(int n = 0) : books(n) { total += n; }

    LibraryVal operator=(const LibraryVal& rhs) {
        total -= books;
        books = rhs.books;
        total += books;
        cout << "LibraryVal::operator= called\n";
        return *this; // returning a temporary
    }

    LibraryVal operator+=(int n) {
        books += n;
        total += n;
        cout << "LibraryVal::operator+= added " << n << " books\n";
        return *this; // returns copy
    }

    LibraryVal operator++() {
        ++books;
        ++total;
        cout << "LibraryVal::operator++ prefix increment (returns by value)\n";
        return *this;
    }

    void show() const { cout << "Library has " << books << " books" << endl; }
    static void showTotal() { cout << "Total books = " << total << endl; }
};

int LibraryVal::total = 0;


int main() {
    LibraryRef a(3), b(5), c(10);
    LibraryRef::showTotal();

    a = b = c;       // chaining works
    a.show(); b.show(); c.show();
    LibraryRef::showTotal();

    (a += 2) += 3;   // chaining works
    ++(++a);         // chaining works
    a.show();
    LibraryRef::showTotal();


    LibraryVal x(2), y(4), z(6);
    LibraryVal::showTotal();

    x = y = z;       // works because result is temporary copy
    x.show(); y.show(); z.show();
    LibraryVal::showTotal();

    // (x = y) = z;   // fails to compile, left-hand side not lvalue
    // (x += 2) += 3; // fails, temporary on LHS
    ++(++x);         // compiles, but increments only temporary not x twice
    x.show();
    LibraryVal::showTotal();

    // Returning by reference supports chaining and modifies same object
    // Returning by value compiles for single operations but breaks chaining
}
