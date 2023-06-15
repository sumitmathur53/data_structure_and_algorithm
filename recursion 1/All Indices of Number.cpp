#include<iostream>
using namespace std;

int allindex(int input[], int size, int x, int output[]){
    
    // if the size is zero

    if(size==0){
        return 0;
    }

    // getting recursive ans

    int ans = allindex(input+1,size-1,x,output);  // it is giving the size of array

     // If the element at index 0 is equal
    // to x then add 1 to the array values
    // and shift them right by 1 step

    if(input[0]==x){
        for(int i = ans-1; i>=0; i--){
            output[i+1] = output[i] +1;
        }

        output[0] = 0;
        ans++;
    }
    else{
        // if index at zero is not equal to x the add 1 array values 
        for(int i=ans-1;i>=0;i--){
            output[i] = output[i]+1 ;
        }

    }
    return ans;
}

// another approach from the last one to check

int index(int arr[], int n, int x, int output[]){
    if(n==0){
        return 0;
    }

    int ans = index(arr,n-1,x,output);

    if(arr[n-1]==x){         // if the last element is yes add the position of that in array output
        output[ans] = n-1;
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