#include <iostream>
#include <string>
using namespace std;

class User {
public:
    User();   // Constructor declaration
    ~User();  // Destructor declaration

private:
    int age = 0;
    string name;
};

// Constructor definition
User::User() {
    cout << "Tauqeer Saleem is eccentric" << endl;
}

// Destructor definition
User::~User() {
    cout << "yessir" << endl;
}

class Name {
private:
    string firstname;
    string lastname;
    User friend;
public:
    Name();   // Constructor
    Name(const string &first); //passed by reference due to avoiding extra copies
    ~Name();  // Destructor
};

// Constructor definition (C++ 17)
Name::Name(): firstname("-") , lastname("-"){
    cout << "Youshae is a ****" << endl;
}
//C++11
Name::Name(const string &first){
    firstname= first;

}


// Destructor definition
Name::~Name() {
    cout << "hamna" << endl;
}

int main() {
    Name A;
    User B;
    return 0;
}
