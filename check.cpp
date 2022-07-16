#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int allindex(int input[], int size, int x, int output[]){
    if(size==0){
        return 0;
    }

    int ans = allindex(input+1,size-1,x,output);

    if(input[0]==x){
        for(int i=ans-1;i>=0;i--){
            output[i+1] = output[i]+1;
        }
        output[0] = 0;
        ans++;
    }else{
        for(int i=ans-1;i>=0;i--){
            output[i+1] = output[i] + 1;
        }
    }
    return ans;
}

int main(){
    int arr[]={1,5,13,96};
    cout<<check(arr,4);

}