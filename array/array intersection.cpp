#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void intersection(int a[], int b[], int n, int m){

    // sort the array
    sort(a,a+n);
    sort(b,b+m);

    int i=0;
    int j=0;

    while(i<n && j<m){
        if(a[i]>b[j]){
            j++;
        }
        else if(b[j]>a[i]){
            i++;
        }else{
            cout<<a[i]<<" ";
            i++;
            j++;
        }
    }
}



