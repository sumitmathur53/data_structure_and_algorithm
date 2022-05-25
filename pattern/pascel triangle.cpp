#include<iostream>
using namespace std;

// pascal triangle;
/*
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 
1 6 15 20 15 6 1 
1 7 21 35 35 21 7 1
*/

int facto(int n){
    int fact = 1;
    for(int i=2;i<=n;i++){
        fact = fact*i;
    }
    return fact;
}

int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<facto(i)/(facto(i-j)*facto(j))<<" ";
        }cout<<endl;
    }
}

