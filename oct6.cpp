#include <iostream>
using namespace std;

class AppleTree{
    private:
    int* Applecount;
    public:
    //Constructor:(RAII principle, parameter required as resources) 
    AppleTree(int initialApples=0) {
        Applecount = new int(initialApples);
        cout << "Tree planted with " << *Applecount << " apples."<<endl;
    }
    //Copy Constructor (Rule of 3)
    AppleTree(const AppleTree& other) {
        Applecount = new int(*other.Applecount); //deep copy
        cout << "Tree copied with " << *Applecount << " apples."<<endl;
    }
    //Copy Assignment Operator (Rule of 3)
    AppleTree& operator=(const AppleTree& other) {
        if (this != &other) { //noself-assignment
            delete Applecount;
            Applecount = new int(*other.Applecount);
            cout << "Tree assigned with" << *Applecount << " apples."<<endl;
        }
        return *this;
    }
     // Destructor (Rule of 3)
    ~AppleTree() {
        cout << "Tree destroyed. Apples were: " << *Applecount << endl;
        delete Applecount;
    }
    //no destructor : memory leak as applecount allocated memory is never deleted,no RAII principle as the resource not released when object dies
    //no copy constructor : shallow copy will point to the memory address., two appletree objects pointing to same applecount
    //no copy operator :same problem as above
    //no dynamic memory allocation for new applecount:deleting a non heap resource/memory address will raise errors
};