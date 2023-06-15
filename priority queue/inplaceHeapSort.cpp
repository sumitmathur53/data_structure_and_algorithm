#include<iostream>
using namespace std;
#include<vector>
#include<climits>

// array 5 8 3 1 6 sort this with heap

// build heap in the itself.
// first part is heap the index 0 and the rest 1 ton-1 is in array

//childindex = 1; parentIndex = (i-1)/2
// insert in heap and up heapify

void inplaceHeapSort(int input[], int n){
    // building heap in input array

    for(int i=1;i<n;i++){

        int childIndex = i;
        
        while(childIndex > 0){                  // build the heap insert function
            int parentIndex = (childIndex-1)/2;

            if(input[childIndex] < input[parentIndex]){
                int temp = input[childIndex];
                input[childIndex] = input[parentIndex];
                input[parentIndex] = temp;               
            }else{
                break;
            }

            childIndex = parentIndex;
        }
    }

    //now we have to write remove function

    int size = n;
    while(size>1){

        int temp = input[0];
        input[0] = input[size-1];
        input[size-1] = temp;

        size--;

        int parentIndex = 0;
        int leftChildIndex = 2*parentIndex+1;
        int rightChildIndex = 2*parentIndex+2;

        while(leftChildIndex < size){
            int minIndex = parentIndex;

            if(input[minIndex] > input[leftChildIndex]){
                minIndex = leftChildIndex;
            }
            if(rightChildIndex < size && input[rightChildIndex]<input[minIndex]){
                minIndex = rightChildIndex;
            }
            if(minIndex == parentIndex){
                break;
            }

            int temp = input[minIndex];
            input[minIndex] = input[parentIndex];
            input[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = parentIndex*2+1;
            rightChildIndex = parentIndex*2+2;

        }

    }
   

}

int main(){
    int input[] = {5,1,2,0,8};

    inplaceHeapSort(input,5);

    for(int i=0;i<5;i++){
        cout<<input[i]<<" ";
    }

    // this will give in decresing order array 
    // to get incearsing array we should do it like max heap insert or remove function
    
}