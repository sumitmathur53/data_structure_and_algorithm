#include<iostream>
using namespace std;

class stackusingarray{

     int *arr;
     int nextindex;
     int capacity;

     public:
     
     stackusingarray(){
        arr = new int[5];
        nextindex = 0;
        capacity = 5;

     }
    // insert element

    void push(int element){
        if(nextindex==capacity){
            int *newarr = new int[2*capacity];
            for(int i=0;i<capacity;i++){
                newarr[i] = arr[i];
            }
            capacity *=2;
            delete[]arr;
            arr = newarr;    
        }
        arr[nextindex] = element;
        nextindex++;
    }

     // return the number of element in stack
    
    int size(){
        return nextindex;
    }

    bool isempty(){
        /*if(nextindex==0){
            return true;
        }else{
            return false;
        }
        */
        return nextindex==0;
    }

    // delete the element;

    int pop(){
        if(isempty()){
            cout<<"stack is empty"<<endl;
            return 1900399;
        }
        nextindex--;
        return arr[nextindex];
    }

    int top(){
        if(isempty()){
            cout<<"stack is empty"<<endl;
            return 1900399;
        }
        return arr[nextindex-1]; 
    }

};

int main(){
    stackusingarray s;

    s.push(20);
    s.push(21);
    s.push(23);
    s.push(24);
    s.push(233);
    
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isempty()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.isempty()<<endl;
}