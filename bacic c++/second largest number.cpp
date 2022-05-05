#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;

    int max = INT_MIN;
    int secmax = INT_MIN;

    int p;//present number
    
    int i=1;
    while(i<=n){
        cin>>p;

        if(p>max){
            secmax = max;
            max = p;
        }else if(p>secmax && p!=max){
            secmax = p;
        }

        i++;
    }

    cout<<secmax;

}