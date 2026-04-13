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
    friend complex add(complex &M,complex &N);
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
complex add(complex &M, complex &N){
    complex sum;
    sum.real = M.real+N.real;
    sum.img = M.img+N.img;
    return sum;
}

void D::display(complex x){
    cout<<x.real<<"+"<<x.img<<"i"<<endl;
}

int main(){
    complex a;// default constructor called
    complex b(2.0, 3.0);// parameterized constructor called
    complex c(b);// copy costructor called
    a = add(b,c);// friend function called

    D dis;
    dis.display(b);
    dis.display(c);
    dis.display(a);

    return 0;
}