#include <iostream>
using namespace std;

class Animal{
    private: 
        int age;
    public:
        Animal():age(0){};
        Animal(int a):age(a){};
        ~Animal(){cout<<"animal passed"<<endl;}
        void ageMe();
        void speak();
};
class Dog:public Animal{
    private:
        int speed;
    public:
        void ageMe();
        void speak();
        Dog():Animal(),speed(0){cout<<"an dog was born"<<endl;}
        Dog(int a, int s):Animal(a),speed(s){cout<<"An animal was born "<<endl;}
        ~Dog(){cout<<"A dog has passed away"<<endl;}

};
class Demon{
    public:
        Demon(){cout<<"Demon created with number "<< ++DemonNum <<endl; }
        ~Demon(){cout<<"Demon created with number "<<DemonNum-- <<endl;}
    private:
        inline static int DemonNum = 0; // c++17 uses inline, we can change the static int within this line.

};
class Chihuahua:public Dog,public Demon{
    public : 
    Chihuahua(): Dog() , Demon(), name("Galaxy Destroyer"){};
    Chihuahua(int a , int s , string n):Dog(a,s),Demon() ,name(n){};
    ~Chihuahua(){cout<<" your chihuahua passed away "<<endl; }
    void EatPoopRepeat() const {cout<< " i ate , i pooed , now i rest"<<endl ;}
    void speak(){cout << "wee  wee "<<endl;}
    private :
        string name;
};

//int Demon::DemonNum = 0;
int main(){
    Chihuahua fluffy;
    fluffy.speak();
}