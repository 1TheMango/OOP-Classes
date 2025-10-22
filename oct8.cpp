
 // We'll compare:
 // AppletreeRef ,operators return by reference (conventional)
 //AppletreeVal , operators return by value (non-reference)
 

#include <iostream>
using namespace std;

class AppletreeRef {
    int apples;
    static int total; //total apples
public:
    AppletreeRef(int n = 0) : apples(n) { total += n; }

    AppletreeRef& operator=(const AppletreeRef& rhs) {
        total -= apples;  // remove old apples
        apples = rhs.apples;
        total += apples;
        cout << "AppetreeRef::operator= called\n";
        return *this; // return reference allows chaining
    }

    AppletreeRef& operator+=(int n) {
        apples += n;
        total += n;
        cout << "AppetreeRef::operator+= added " << n << " apples\n";
        return *this; 
    }

    AppletreeRef& operator++() {
        ++apples;
        ++total;
        cout << "AppetreeRef::operator++ prefix increment\n";
        return *this; // allows ++(++a)
    }

    void show() const { cout << "Tree has " << apples << " apples"<<endl; }
    static void showTotal() { cout << "Total apples = " << total << endl; }
};

int AppletreeRef::total = 0;

class AppletreeVal {
    int apples;
    static int total;
public:
    AppletreeVal(int n = 0) : apples(n) { total += n; }

    // Assignment operator returning by value
    AppletreeVal operator=(const AppletreeVal& rhs) {
        total -= apples;
        apples = rhs.apples;
        total += apples;
        cout << "AppetreeVal::operator= called\n";
        return *this; // returning a temporary
    }

    AppletreeVal operator+=(int n) {
        apples += n;
        total += n;
        cout << "AppetreeVal::operator+= added " << n << " apples\n";
        return *this; //creates a copy
    }

    AppletreeVal operator++() {
        ++apples;
        ++total;
        cout << "AppetreeVal::operator++ prefix increment (returns by value)\n";
        return *this;
    }

    void show() const { cout << "Tree has " << apples << " apples"<<endl; }
    static void showTotal() { cout << "Total apples = " << total << endl; }
};

int AppletreeVal::total = 0;



int main() {
    AppletreeRef a(3), b(5), c(10);
    AppletreeRef::showTotal();

    a = b = c;           //chaining works
    a.show(); b.show(); c.show();
    AppletreeRef::showTotal();

    (a += 2) += 3;       //chaining works
    ++(++a);             //chaining works
    a.show();
    AppletreeRef::showTotal();


    AppletreeVal x(2), y(4), z(6);
    AppletreeVal::showTotal();

    x = y = z;           // still works because result is a temporary copy
    x.show(); y.show(); z.show();
    AppletreeVal::showTotal();

    // (x = y) = z;      // this fails to compileleft-hand side is not lvalue
    // (x += 2) += 3;    // also fails(temporary on LHS)
    ++(++x);             //compiles, but increments only temporary not x twice
    x.show();
    AppletreeVal::showTotal();
    //ref by value complies for single ops like += but doesnt do chaining , compling

   
}
