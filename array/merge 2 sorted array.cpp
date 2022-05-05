#include<iostream>
using namespace std;

void merge(int arr1[], int arr2[], int n1, int n2, int arr3[]){

    int i=0,j=0;
    int k=0;

    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr3[k] = arr1[i];
            k++;
            i++;
        }else{
            arr3[k]=arr2[j];
            k++;
            j++;
        }
    }

    while(i<n1){
        arr3[k]=arr1[i];
        i++;
        k++;
    }

    while(j<n2){
        arr3[k]=arr2[j];
        j++;
        k++;
    }
}