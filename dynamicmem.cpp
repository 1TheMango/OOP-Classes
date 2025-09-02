#include <iostream>
using namespace std;

int main(){

    /*int* new_int = new int; //dyanmic memory allocation
    *new_int= 5;
    delete new_int; // memoryleaks
    new_int = nullptr; //dangling pointer

    int size;
    cin>>size;
    int* new_array =new int[size];

    /
    do whatever
    
   delete[] new_array;
   new_array;
   */

   struct list{
    int size =0;
    int* arr = nullptr;
    
    void add(int x){
        size+=1;
        int* new_arr =new int[size];
        for(int i=0; i<(size-1); i++){
            new_arr[i]=arr[i];
        }
        new_arr[size-1]=x;
        delete[] arr;
        arr= new_arr;
        //new_arr= nullptr;
    };

   };
   list newlist;
   newlist.add(4);
   newlist.add(56);
   for(int i=0;i<newlist.size; i++){
    cout<<newlist.arr[i]<<endl;
   }





};