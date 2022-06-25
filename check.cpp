#include<iostream>
using namespace std;
#include<bits/stdc++.h>


class student{
    public:
    int rollnumber;
    private:
    int age;
    public:
    // default constructor
    student(){
        cout<<"contructor called"<<endl;
    }
    // parameterised constructor;
    student(int r){
        cout<<"contructor 2 called"<<endl;
        rollnumber = r;
    }
    student(int a, int r){
        cout<<"constructor 3 called"<<endl;
        this->age = a;
        this->rollnumber = r;
    }

    void display(){
        cout<<age<<" "<<rollnumber<<endl;
    }
    
    // distructor
    ~student(){
        cout<<"distructor called"<<endl;
    }

};

int main(){
   student s1;  // contructor 1 called
   student s2(100);  // constructor2 called
   student s3(12,1233); // constructor 3 called

   student s4(s3);  // copy constructor called

   s1 = s2;  // cpy assignment operator

   student s5 = s4;  // student s5(s4); cpy constructor called
   
}