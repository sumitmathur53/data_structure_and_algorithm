#include<iostream>
#include<unordered_map>
using namespace std;

void printInterSection(int arr1[], int n, int arr2[], int m){
    unordered_map<int, int> map;

    for(int i=0;i<n;i++){
        map[arr1[i]]++;
    }

    for(int i=0;i<m;i++){
        if(map[arr2[i]]>0){
            cout<<arr2[i]<<" ";
            map[arr2[i]]--;
        }
    }
}