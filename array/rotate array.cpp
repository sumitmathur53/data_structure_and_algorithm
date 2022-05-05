#include<iostream>
using namespace std;

void reverse(int arr[], int n, int s, int e){
    

    while(s<e){
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++;
        e--;
    } 
}

void rotate(int *input, int d, int n)
{   
    reverse(input,n,0,n-1);
    reverse(input,n,0,n-d-1);
    reverse(input,n,n-d,n-1);
}