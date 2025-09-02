#include <iostream>
using namespace std;

int main(){

    int* new_int = new int; //dyanmic memory allocation
    *new_int= 5;
    delete new_int; // memoryleaks
    new_int = nullptr; //dangling pointer

    int size;
    cin>>size;
    int* new_array =new int[size];

    /*
    do whatever
    */
   delete[] new_array;
   new_array;

   struct list{
    int size =0;
    int* arr = nullptr;
    int* new_int = new int[size+1]


   }
}