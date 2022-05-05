#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        int val=i;
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        for(int k=1;k<=i;k++){
            cout<<val;
            val++;
        }
        int v = 2*i-2;
        for(int j=i-1;j>=1;j--){
            cout<<v;
            v-=1;
        }cout<<endl;
    }
}