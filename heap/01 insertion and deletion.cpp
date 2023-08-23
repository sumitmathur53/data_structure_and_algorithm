#include<iostream>
using namespace std;


class heap {
    public:

    int arr[100];
    int size = 0;

    void insert(int val){
        size += 1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent] , arr[index]);
                index = parent;
            }
            else{
                return;
            }

        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    void deletefromheap(){  // this function will delete the top element
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }

        // put last element into first index

        arr[1] = arr[size];

        // remove the last element;
        size--;

        //take root to ots correct position

        int i = 1;
        while(i<size){
            int leftindec = 2*i;
            int rightindex = 2*i+1;

            if(leftindec < size && arr[i] < arr[leftindec] ){

                swap(arr[i] , arr[leftindec]);
                i = leftindec;
            }
            else if(rightindex < size && arr[i] < arr[rightindex]){
                swap(arr[i] , arr[rightindex]);
                i = rightindex;
            }
            else{
                return;
            }
        }
    }

};

int main(){
    heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    

    h.print();

    h.deletefromheap();
    h.print();

}