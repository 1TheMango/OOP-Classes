#include <iostream>
using namespace std;
class Person{
    public:
        //methods
        void showFriends();
        void addFriend(Person*);
        ~Person();
        Person();
        Person(const Person&);
        Person(const string&,Person**);
        int getPeople(){return People;}

    private:
    string name;
    Person** connections;
    int CountFriends;
    static int People;

};
Person::~Person(){
    delete[] connections;
    People--;
}
int Person::People = 0;
Person::Person():name("kutch b"),CountFriends(0),connections(nullptr){
People++;
};
Person::Person(const string& n,Person** con): name(n),CountFriends(0),connections(con){
People++;
};
Person::Person(const Person& per): name(per.name),CountFriends(per.CountFriends),connections(new Person*[per.CountFriends]){
    copy(per.connections, per.connections+ CountFriends,connections);
    People++;
}
Person& Person::operator=(const Person&){
    
}
int main(){
    Person A;
    cout << A.getPeople() <<endl;
    Person B;
    cout<< B.getPeople() << endl;
    Person C = B;
    Person D(C);
    cout<<D.getPeople() <<endl;

}
