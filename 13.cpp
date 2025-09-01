#include <iostream>

using namespace std;

int main(){
    int integer= 10;

    int* integer_pointer = &integer; //referencing

    cout<< integer_pointer <<endl;
    cout<<*integer_pointer<<endl; //dereferencing

    integer_pointer = NULL;
    integer_pointer = nullptr; ///more reliable for null pointer

    typedef const unsigned long long int* culli;
    //same thing as above but not recommended
    using culli = const unsigned long long int*;
    using int_ptr= int*;

    
}