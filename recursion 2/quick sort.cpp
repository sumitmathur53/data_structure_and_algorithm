#include<iostream>
using namespace std;

int partition1(int a[], int s, int e){
    int pivot = a[s];

    // how many element smaller than equal to this
    int countsmaller = 0;
    for(int i=s+1;i<=e;i++){
        if(a[i]<pivot){
            countsmaller++;
        }
    }

    int pivotindex = countsmaller+s;
    a[s] = a[pivotindex];
    a[pivotindex] = pivot;  // now our pivot element goes AT RIGHT PLACE

    // i have to deal with the smaller should be left of pivot
    // and greater at right of pivot

    int i=s;
    int j=e;
    while(i<pivotindex && j>pivotindex){
        if(a[i]<=pivot){                        // if element in left is small nothing we need to do
            i++;
        }else if(a[j]>pivot){                  // if element in right is small nothing we need to do
            j--;
        }else{                                // if both the wrong then swap them...
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    return pivotindex;
}

void quicksort(int a[], int s, int e){
    if(s>=e){
        return;
    }

    int p = partition1(a,s,e);
    quicksort(a,s,p-1);
    quicksort(a,p+1,e);
}


// another approarck

void swap(int arr[], int i, int j){

    int temp = arr[i];
    arr[i] =arr[j];
    arr[j] = temp;
    
}

int partition(int arr[], int l, int r){

    int pivot = arr[r];

    int i = l-1;

    for(int j=l; j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);    

        }
    }
    
    // i  is the last position of last no which is less than pivot
    // so i+1 position to be placed for pivot 
    swap(arr,i+1,r);
    return i+1;
}

void qsort(int arr[], int l, int r){
    if(l>=r){
        return;
    }

    int pi = partition(arr,l,r);
    qsort(arr,l,pi-1);
    qsort(arr,pi+1,r);
}

int main(){
    int a[] = {5,8,7,-3,0,0,2,1,9};
    qsort(a,0,8);
    for(int i=0;i<8;i++){
        cout<<a[i]<<" ";
    }
}