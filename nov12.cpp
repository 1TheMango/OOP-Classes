#include <iostream>
using namespace std;

class INT{
    private:
        int data;
    public:
        INT(): data(0) {}
        INT(int d): data(d) {}
        ~INT() {}
        INT operator+(const INT& other) const {
            return INT(this->data + other.data);
        }
        void getdata() const {
            cout << "Data: " << data << endl;
        }
        INT& operator++() {
            ++data;
            return *this;
        }
        INT operator++(int) {
            INT temp = *this;
            ++data;
            return temp;
        }
        friend ostream& operator<<(ostream& out, const INT& A);
        friend istream& operator>>(istream& in , INT& A);
        friend istream& getline(istream& in, INT& A);
        INT& operator=(INT other){
            if (data == other.data){
                return *this;
            }
            else{
                data = other.data;
            }
            return *this;
        }
        
};
ostream& operator<<(ostream& out, const INT& A){
    out << A.data;
    return out;
}
istream& operator>>(istream& in , INT& A){
    in>>A.data;
    //getline(in,A.data); //data should be int;
    return in;
}


int main() {
    INT a(1);
    INT b(5);
    cout<< a << endl;
    cout << a <<"  " << b <<endl;
    cout<<"what is ur number might guy"<<endl;
    cin>>a;
    return 0;
}