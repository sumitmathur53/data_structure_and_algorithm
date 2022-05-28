#include<iostream>
using namespace std;

int findDuplicate(int *arr, int n)
{
    //Write your code here
    int sumofnminus2 = ((n-2)*(n-1))/2;
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=arr[i];
    }
    return ans-sumofnminus2;
}
