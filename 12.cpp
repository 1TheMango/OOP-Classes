#include <iostream>
using namespace std;
int main(){
    const int MAX =100;
    char str[MAX] = "";

    int array[3]{};
    cin.getline(str,MAX); // normal cin>>str will only get the first word , not the spaces
    cout<< "Your String" << str<<endl;

}