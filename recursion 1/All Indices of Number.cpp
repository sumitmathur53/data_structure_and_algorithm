#include<iostream>
using namespace std;

int allindex(int input[], int size, int x, int output[]){
    if(size==0){
        return 0;
    }

    int ans = allindex(input,size-1,x,output);

    if(input[size-1]==x){
        output[ans]=size-1;
        ans++;
    }
    return ans;
}

void print(int input[],int n,int x){
    int output[n];
    int size = allindex(input,n,x,output);
    for(int i=0;i<size;i++){
        cout<<output[i]<<" ";
    } 
}

int main()
{
    int arr[] = { 1, 2, 3, 2, 2, 5 };
    int x = 2;
     
    int n = sizeof(arr) / sizeof(arr[0]);
     
    // Function call
    print(arr, n, x);
     
    
}