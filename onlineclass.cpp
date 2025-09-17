#include <iostream>
using namespace std;
int main(){
    int arr[5]{1,2,3,4,5};
    for (int i=0;i<5;i++){
        cout<<*(arr+i)<<endl;


    }
    struct list
    {
        int count = 0;
        int* array= nullptr;
        //function overloading:
        void append(int x){

        }
        void append(int* x){

        }

    };
    int x =5;
    
}