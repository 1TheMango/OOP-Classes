#include <iostream>

using namespace std;

void exchange(int& x , int& y){ //pass by reference
    int a = x;
    int b= y;
    y= a;
    x=b;
}

int main(){
    int x=1;
    int y=3;
    exchange(x,y);
    cout<< x << ","<< y<<endl;

    int a_var = 10;
    int& alias_a = a_var;
    
}