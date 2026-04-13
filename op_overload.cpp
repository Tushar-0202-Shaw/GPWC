//Addition of 2 complex numbers using friend function
#include<iostream>
using namespace std;
class complex;
class D{
    public:
    D(){}
    void display(complex x);
};// forward declaration
class complex{
    float real, img;
    public:
    complex();// default constructor
    complex(float i, float j);// parameterized constructor
    complex(complex &);// copy constructor
    complex operator + (complex &x);
    //friend void D::display(complex x);
    friend class D;
};

complex::complex(){
    real = 0.0;
    img = 0.0;
}
complex::complex(float i, float j){
    real= i;
    img = j;
}
complex::complex(complex &obj){
    real= obj.real;
    img = obj.img;
}

complex complex::operator+(complex &x){
    complex sum;
    sum.real = real+x.real;
    sum.img = img+x.img;
    return sum;
}

void D::display(complex x){
    cout<<x.real<<"+"<<x.img<<"i"<<endl;
}

int main(){
    complex a;// default constructor called
    complex b(2.0, 3.0);// parameterized constructor called
    complex c(b);// copy costructor called
    a = b+c;// operator overload function called -> a=b.operator+(c)

    D dis;
    dis.display(b);
    dis.display(c);
    dis.display(a);

    return 0;
}