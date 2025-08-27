#include <iostream>

using namespace std;

int main(){
    int a=1;
    cout<<++a<<endl; //pre increment
    cout<<++a<<endl;
    cout<<a++<<endl;
    cout<<a<<endl; //post increament

    bool isthisclassboring = false;
    bool iscppboring = true;
    bool experience = isthisclassboring && /*this is basically and*/ iscppboring;
    cout<<experience<<endl;
}