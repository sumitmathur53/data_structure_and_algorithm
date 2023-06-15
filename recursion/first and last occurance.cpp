#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int firstlocc(int arr[], int n,int i,int key){

    if(i==n){
        return -1;
    }

    if(arr[i]==key){
        return i;
    }

    return firstlocc(arr,n,i+1,key);

}

int lastloc(int arr[], int n, int i, int key){

    if(i==n){
        return -1;
    }

    int rest = lastloc(arr,n,i+1,key);

    if(rest!=-1){
        return rest;
    }

    if(arr[i]==key){
        return i;
    }
    return -1;
}

int main(){
    int arr[] = {4,3,41,4,55,4,5};
    cout<<lastloc(arr,7,0,4)<<endl;
    cout<<firstlocc(arr,7,0,4)<<endl;
}