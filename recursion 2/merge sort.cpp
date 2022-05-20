#include<iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end){
    int n1 = mid-start+1;
    int n2 = end-mid;

    int a[n1];
    int b[n2];

    for(int i=0;i<n1;i++){
        a[i] = arr[start+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }

    int i=0,j=0;
    int k=start;

    while(i<n1 && j<n2){
         if(a[i]<b[j]){
             arr[k]=a[i];
             i++;
             k++;
         }else{
             arr[k]=b[j];
             j++;
             k++;
         }
    }

    while(i<n1){
        arr[k]=a[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=b[j];
        j++;
        k++;
    }

}

void mergsort(int arr[], int start, int end){
    if(start>=end){
        return;
    }
    int mid = (start+end)/2;

    mergsort(arr,start,mid);
    mergsort(arr,mid+1,end);
    merge(arr,start,mid,end);
}

int main(){
    int arr[]={8,31,3,-4,66,33};
    mergsort(arr,0,6);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}