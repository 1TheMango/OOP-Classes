struct  Complex{
    double real;
    double imaginary;
    Complex():real(0),imaginary(0){};
    Complex(double r,double i):real(r),imaginary(i){};

};

Complex operator+(Complex &a,Complex &b){
        return Complex(a.real+b.real,a.imaginary+ b.imaginary);
    }
Complex operator-(Complex &a,Complex &b){
    return Complex(a.real-b.real,a.imaginary-b.imaginary);
}
Complex operator*(Complex &a,Complex &b){
    return Complex((a.real*)
}