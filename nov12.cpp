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
        
};
ostream& operator<<(ostream& out, const INT& A){
    cout<<A.data<<endl;

}

int main() {
    INT a(1);
    INT b(5);
    cout<< A << endl;
    cout << A << B <<endl;
    return 0;
}