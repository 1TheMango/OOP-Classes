#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;



const int ROW = 2;
const int COL = 2;

int random_function_1(int input){
    return 0;
}

int main(){
    int arr[2][3]={1,2,3,4}; //same as int arr[2][3]{{1,2,3},{4,0,0}}
    random_function_1(2);
    //manipuator chain
    float PI= 3.1415926535;
    double X1= 2.1233213123131231;

    cout<<fixed<<setprecision(15);

    cout<<PI<<endl;
    cout<<X1<<endl;
    float a = 0.1;
    float b = 0.2;
    double sum = a + b;

    if (sum==0.3) cout << "YAYYY"<<endl;
    else cout<<" NAYYYY"<<endl;

    if (fabs(sum - 0.3) < 1e-17) cout << "Finally" << endl;
    else cout << "WHAT?" << endl;

    //enum - enumerator
    // monday, tuesday ...sunday
    enum week {MONDAY,TUESDAY,WEDNESDAY};
    int in;cout<<"in";cin>>in;

    switch(in){
        case MONDAY:
            cout<<"It's Monday";
            break;
        default:
            cout<<"NAHHH";

    }

}