#include<iostream>
using namespace std;


int main(){

      int n,m;
      cin>>n>>m;
      
    int arr[1000][1000];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=0;i<m;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            sum+=arr[j][i];           
        }
        cout<<sum<<" ";
    }
  
}
