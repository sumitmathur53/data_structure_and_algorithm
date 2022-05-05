#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        char start = 'A'+i-1;
        for(int k=1;k<=i;k++){
            cout<<(char)(start+k-1);
        }cout<<endl;
    }
}