#include <iostream>
using namespace std;
class Buffer{
    private:
        char* arr;
        int size;
    public:
        Buffer(int sizecopy){
            size=sizecopy;
            new char[sizecopy];

        }
        Buffer();


};
