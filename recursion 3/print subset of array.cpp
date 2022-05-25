#include<iostream>
using namespace std;



void print(int input[], int n, int output[], int m){
    
   if(n==0){                   // if size zero print the output
       for(int i=0;i<m;i++){
           cout<<output[i]<<" ";
       }cout<<endl;
       
       return;
   }
    
    print(input+1,n-1,output,m);
    int newoutput[m+1];         // creating the new output
    for(int i=0;i<m;i++){         // copying the all element in newone
        newoutput[i] = output[i];
    }
    newoutput[m] = input[0];    // adding first elemnt
    
    print(input+1,n-1,newoutput,m+1);
    
}

void printSubsetsOfArray(int input[], int size) {
	
    int output[0];
    print(input,size,output,0);
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
