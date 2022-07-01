#include<iostream>
using namespace std;

class dynamicarray{
    int *data;
    int nextindex;
    int capacity;   // total size

    public:

    dynamicarray(){
        data = new int[5];
        nextindex = 0;
        capacity = 5;
    }

    void add(int element){
        if(nextindex==capacity){
            int *newdata = new int[2*capacity];
            for(int i=0;i<capacity;i++){
                newdata[i] = data[i];
            }
            delete [] data;       // dealocate previous array
            data = newdata;       // pointing the previous array to new
            capacity = 2*capacity;
        }
        data[nextindex] = element;
        nextindex++;
    }

    int get(int i){
        if(i<nextindex){
            return data[i];
        }else{
            return -1;
        }
    }
    

    void add(int i, int element){
        if(i<nextindex){
            data[i]=element;
        }else if(i==nextindex){
            add(element);
        }else{
            return ;
        }

    }

    dynamicarray(dynamicarray const &d){
       // this->data = d.data; // shallow copy

       // deep copy
        this->data = new int[d.capacity]; 
        for(int i=0;i<d.nextindex;i++){
           this->data[i] = d.data[i];
        }
        this->nextindex = d.nextindex;
        this->capacity = d.capacity;
    }
    

    void operator=(dynamicarray const &d){
        this->data = new int[d.capacity]; 
        for(int i=0;i<d.nextindex;i++){
           this->data[i] = d.data[i];
        }
        this->nextindex = d.nextindex;
        this->capacity = d.capacity;
    }
    void print(){
        for(int i=0;i<nextindex;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    dynamicarray d1;
    d1.add(10);
    d1.add(22);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    
    d1.print();
    cout<<endl;
    
    dynamicarray d2(d1);  // inbuild copy constructor do shalow copy
    d1.add(0,100);
    d2.print();

    dynamicarray d3;
    d3=d1;
    d1.add(1,500);

    d2.print();
    d1.print();
    d3.print();
     


}