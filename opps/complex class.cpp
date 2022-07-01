#include<iostream>
using namespace std;

class ComplexNumbers {
    // Complete this class
    public:
    int real;
    int imaginary;
    
    ComplexNumbers(int x, int y){
        this->real = x;
        this->imaginary = y;
    }
    
    void plus(ComplexNumbers const &c2){
        real = real + c2.real;
        imaginary = imaginary + c2.imaginary;
    }
    
    void multiply(ComplexNumbers c2){
        int x = this->real;
        this->real = (real * c2.real) - (imaginary * c2.imaginary);
        this->imaginary = (x*c2.imaginary) + (imaginary*c2.real);
    }
    
    void print(){
        cout<<real<<" "<<"+"<<" "<<"i"<<imaginary<<endl;
    }
};