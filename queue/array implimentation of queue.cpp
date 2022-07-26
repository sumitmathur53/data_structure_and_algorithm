#include<iostream>
using namespace std;

template<typename T>
class queueusingarray{
    T * arr;
    int nextindex;
    int frontindex;
    int size;
    int capacity;

    public:

    queueusingarray(int s){
        arr = new T[s];
        nextindex = 0;
        frontindex = -1;
        size = 0;
        capacity = s;
    }

    int getsize(){
        return size;
    }

    bool isempty(){
        return size==0;
    }

    // inserting the element

    void enqueue(T element){
        if(size==capacity){
            T * newarr = new T[2*capacity];
            int j=0;
            for(int i=frontindex; i<capacity; i++){
                newarr[j] = arr[i]; 
                j++;
            }
            for(int i=0;i<frontindex;i++){
                newarr[j] = arr[i];
                j++;
            }
            delete[]arr;
            arr = newarr;
            frontindex=0;
            nextindex = capacity;
            capacity *=2;
        }
        arr[nextindex] = element;
        nextindex = (nextindex+1)%capacity;   // if next index is equal to capacity then it is equal to 0 
                                              // cyclic adding fron the front
        if(frontindex==-1){
            frontindex++;
        }
        size++;
    }

    T front(){
        if(isempty()){
            cout<<"empty"<<endl;
            return 0;  // why we returning zero because in char int flot is valid
        }
        return arr[frontindex];
    }
    
    T dequeue(){
        if(isempty()){
            cout<<"empty"<<endl;
            return 0;  // why we returning zero because in char int flot is valid
        }
        
        T ans = arr[frontindex];
        frontindex = (frontindex+1)%capacity;
        size--;
        
        if(size==0){   // optional
            frontindex = -1;
            nextindex = 0;
        }
        return ans;
    }

};

int main(){
    queueusingarray<int> q(5);

    q.enqueue(10);
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(14);
    q.enqueue(15);
    q.enqueue(90);

    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.getsize()<<endl;
    cout<<q.isempty()<<endl;

}