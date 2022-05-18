#include<iostream>
using namespace std;


int countZeros(int n) {
    
    if(n==0){          // this is handle if we give only n=0;
        return 1;
    }
    if(n<10){      
        return 0;
    }
    
    if(n%10==0){
        return 1+countZeros(n/10);
    }else{
        return countZeros(n/10);
    }
    
}

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
