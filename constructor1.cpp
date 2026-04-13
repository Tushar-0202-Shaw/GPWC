#include<iostream>

using namespace std;

class A{
    int x, y;
    public:
    	A(); // declaration of default constructor  
    	A(int m); // declaration of paramaterized constructor  
    	A(A &obj); //declaration of copy constructor
};


A::A(){
    x = 0;
    y = 0;
    cout<<"default constructor is invoked."<<endl;
}

A::A(int m){
    x = m;
    y = m;
    cout<<"parameterized constructor is invoked."<<endl;
}

A::A(A &obj){
    x = obj.x;
    y = obj.y;
    cout<<"copy constructor is invoked."<<endl;
}

int main(){
    A obj1;//default constructor invoked
    //A obj2;	
    A obj2(10); //parameterized constructor invoked
    A *obj3 = new A(10);
    A obj4(obj2);


return 0;
}
