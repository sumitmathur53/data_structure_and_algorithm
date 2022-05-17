#include<iostream>
using namespace std;

int octaltodecimal(int n){
    int ans = 0;
    int oct = 1;

    while(n>0){
        int last = n%10;
        ans += last*oct;
        oct*=8;
        n = n/10;
    }
    return ans;

}
int main(){
    int n;
    cin>>n;

    cout<<octaltodecimal(n);
}