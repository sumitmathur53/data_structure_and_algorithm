#include<iostream>
using namespace std;

template<typename T>

class stackusingarray{

     T *arr;
     int nextindex;
     int capacity;

     public:
     
     stackusingarray(){
        arr = new T[5];
        nextindex = 0;
        capacity = 5;

     }
    // insert element

    void push(T element){
        if(nextindex==capacity){
           T *newarr = new T[2*capacity];
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

    T pop(){
        if(isempty()){
            cout<<"stack is empty"<<endl;
            return 0;
        }
        nextindex--;
        return arr[nextindex];
    }
    T top(){
        if(isempty()){
            cout<<"stack is empty"<<endl;
            return 0;
        }
        return arr[nextindex-1]; 
    }
};

int main(){
    stackusingarray<char> s;

    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    
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