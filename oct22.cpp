#include <iostream>
using namespace std;

class Animal {
private:
    int age;

public:
    Animal() : age(0) {cout<<"yessir"<<endl;}
    Animal(int a) : age(a) {}
    virtual ~Animal() { cout << "animal passed" << endl; }

    // Make them virtual so derived classes can override them
    virtual void ageMe() {
        age++;
        cout << "Animal aged to " << age << endl;
    }

    virtual void speak() {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal {
private:
    int speed;

public:
    Dog() : Animal(), speed(0) { cout << "A dog was born" << endl; }
    Dog(int a, int s) : Animal(a), speed(s) { cout << "An animal was born " << endl; }
    ~Dog() override { cout << "A dog has passed away" << endl; }

    // override keyword helps catch mistakes
    void ageMe() override {
        cout << "Dog is growing older faster!" << endl;
    }

    void speak() override {
        cout << "Woof woof!" << endl;
    }
};

class Demon {
public:
    Demon() { cout << "Demon created with number " << ++DemonNum << endl; }
    ~Demon() { cout << "Demon destroyed with number " << DemonNum-- << endl; }

private:
    inline static int DemonNum = 0;
};

class Chihuahua : public Dog, public Demon {
public:
    Chihuahua() : Dog(), Demon(), name("Galaxy Destroyer") {}
    Chihuahua(int a, int s, string n) : Dog(a, s), Demon(), name(n) {}
    ~Chihuahua() override { cout << "Your chihuahua passed away" << endl; }

    void speak() override { cout << "Wee wee!" << endl; }

    void EatPoopRepeat() const { cout << "I ate, I pooed, now I rest" << endl; }

private:
    string name;
};

//int Demon::DemonNum = 0;
class Angel{
public:

    Angel() { cout << "An angel is born" << endl; }
    ~Angel() { cout << "An angel has ascended" << endl; }
    virtual void speak() { cout << "Angelic choir sings" << endl; }
private:
    string name;
    int age;
};
class Labrador:public Dog, public Angel{
public:
    Labrador():Dog(),Angel(){ cout<<"A labrador is born"<<endl; }
    ~Labrador(){ cout<<"A labrador has passed away"<<endl; }
    void speak() override { cout << "Labrador barks!" << endl; }
};

int main() {
    // Demonstrate polymorphism
    Animal* pet = new Chihuahua();
    pet->speak();    // Calls Chihuahua's speak() due to virtual function
    pet->ageMe();    // Calls Dog's ageMe() since Chihuahua didn’t override it

    delete pet; // Observe destructors called in proper order
}
