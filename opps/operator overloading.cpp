#include<iostream>
using namespace std;
#include<bits/stdc++.h>


#include<iostream>
using namespace std;

class fraction{
    private :
       int numerator;
       int denominator;
    
    public :
       fraction(int numerator, int denominator){
         this->numerator = numerator;
         this->denominator = denominator;
       }

       void print(){
          cout<<this->numerator <<"/"<<this->denominator<<endl; // this is optional here
       }

       // adding two fraction
        void simplify(){
          int gcd = 1;  //greatest common factor
          int j = min(this->numerator,this->denominator);
          for(int i=1;i<=j;i++){
              if(this->numerator%i==0 && this->denominator%i==0){
                gcd=i;
              }
            }
          this->numerator = this->numerator/gcd;
          this->denominator = this->denominator/gcd;  
        }

       fraction operator+(fraction const &f2) const {
         int lcm = denominator * f2.denominator;
         int x = lcm/denominator;
         int y = lcm/f2.denominator;

         int num = x*numerator + (y*f2.numerator);

         fraction fnew(num,lcm);

         //simplified fractiom 
         fnew.simplify();
         return fnew;
         
       }

       fraction operator*(fraction const &f2) const {
        int n = numerator * f2.numerator;
        int d = denominator * f2.denominator;

        fraction fnew(n,d);
        fnew.simplify();
        return fnew;
       }
      
       void multiply(fraction const &f2){
        numerator = numerator * f2.numerator;
        denominator = denominator * f2.denominator;
        
        simplify();
       }

       bool operator==(fraction const &f2) const {
        return (numerator==f2.numerator && denominator==f2.denominator);
       }
       
       // pre increment
       fraction& operator++(){
        numerator = numerator+denominator;
        simplify();

        return *this;    // returning the content
       }

       // post increment
       
       fraction operator++(int){
         fraction fnew(numerator,denominator);
         numerator = numerator+denominator;
         simplify();
         fnew.simplify();
         return fnew;
       }
       
       // operator +=

       fraction& operator+=(fraction const &f2){
         int lcm = denominator * f2.denominator;
         int x = lcm/denominator;
         int y = lcm/f2.denominator;

         int num = x*numerator + (y*f2.numerator);

         numerator=num;
         denominator=lcm;
         simplify();
         return *this;
       }
      
};

int main(){
    fraction f1(10,2);
    fraction f2(15,4);

    f1+=f2;
    f1.print();

    // fraction f3 = f1++;
    // f3.print();
    // f1.print();
    
    // fraction f3 = ++(++f1);
    // f1.print();
    // f3.print();


    // fraction f3 = f1+(f2);
    // f1.print();
    // f2.print();
    // f3.print();

    // fraction f4 = f1*f2;
    // f4.print();
    // fraction f5(75,4);
    
    // if(f5==f4){
    //     cout<<"equal"<<endl;
    // }else{
    //     cout<<"not equal";
    // }
    
    



}