#include <iostream>

using namespace std;

int main(){
    int age;
    string name;
    struct Person{
        int age;
        string name;
        Person* pal;
    };
    Person Tauqeer;
    Tauqeer.name = "Tauqeer";
    Tauqeer.age = 100;

    Person Karim;
    Karim.name ="Karim";
    Karim.age=2000;

    Tauqeer.pal =&Karim;
    Karim.pal=&Tauqeer;

    cout <<Karim.pal->name<<endl; //dereferencing and then taking it out

    // cout<<Karim.(*pal).age<<endl; will give precedence to .age first due to the compiler hence Karim.pal->name
    //lopping arrays by increment the pointer in memory :
    int arr[]={1,2,3};
    for (int j=0 ; j<3;j++){
        cout<<*(arr+j)<<endl;
    }
    //cant do arr_2[5]=arr , even tho theyare the same size,instead:
    int arr[]={1,2,3,4,5};
    int* ptr= arr;
    int* ptr2;
    ptr2=ptr;


}