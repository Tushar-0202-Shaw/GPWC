#include<iostream>
using namespace std;
class vector{
    static const int size = 3;
    int v[size];
    public:
        vector();
        vector(int *x);
    friend vector operator *(int a, vector &b);
    friend vector operator *(vector &b, int a);
    friend istream & operator >>(istream &, vector &);
    friend ostream & operator <<(ostream &, vector &);
};
vector:: vector(){
    for(int i=0;i<size;i++){
        v[i]=0;
    }
}
vector::vector(int *x){
    for(int i=0;i<size;i++){
        v[i]=x[i];
    }
}
vector operator *(int a, vector &b){ // friend-1
    vector c;
    for(int i=0;i<vector::size;i++){
        c.v[i] = a*b.v[i];
    }
    return c;
}
vector operator *(vector &b, int a){ // friend-2
    vector c;
    for(int i=0;i<vector::size;i++){
        c.v[i] = b.v[i]*a;
    }
    return c;
}
istream& operator >>(istream &din, vector &b){ // friend-3
    for(int i=0;i<vector::size;i++){
        din>>b.v[i];
    }
    return din;
}
ostream& operator <<(ostream &dout, vector &b){ // friend-4
    dout<<"("<<b.v[0];
    for(int i=1;i<vector::size;i++){
        dout<<","<<b.v[i];
    }
    dout<<")";
    return dout;
}
int x[] = {2,4,6};
int main(){
    vector a; //default constructor called
    vector b = x; // equilavlent to vector b(x) -> parameterized constructor called
    int i=2;
    vector c = i*b; //friend-1 called
    vector d = b*i; //friend-2 called
    cout<<"Input for a 3-D vector: ";
    cin>>a; //friend-3 called
    cout<<"Vector a = "<<a<<endl; //friend-4 called
    cout<<"Vector b = "<<b<<endl;
    cout<<"Vector c = "<<c<<endl;
    cout<<"Vector d = "<<d<<endl;
    return 0;
}