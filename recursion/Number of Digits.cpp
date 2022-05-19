#include<iostream>
using namespace std;

int count(int n){
    
    
    if(n==0){   // base case
        return 0;
    }
    
    int small = n/10;   
    int ans = 1+count(small);
    return ans;
}


int main(){
    int n;
    cin >> n;
  
    cout << count(n) << endl;
}


