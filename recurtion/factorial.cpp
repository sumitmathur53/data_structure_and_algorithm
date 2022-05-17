#include<iostream>
using namespace std;

int fact(int n){
   if(n==0){
       return 1;
   }
   int factorial = fact(n-1);
   int output = n*factorial;
   return output;
}

int main(){
    cout<<fact(4);
}