#include<iostream>
using namespace std;
#include<vector>

class PriorityQueue{

    vector<int> pq;

    public:

    PriorityQueue(){

    }

    bool isEmpty(){
        return pq.size()==0;
    }
    
    // return size or no. of element present
    int getSize(){
        return pq.size();  
    }

    int getMin(){
        if(pq.size()==0){
            return 0; // priority queue is empty
        }
        return pq[0];
    }

    void insert(int element){
        pq.push_back(element);

        int childIndex = pq.size()-1;

        while(childIndex > 0){         // this when we go till root in search of min
            int parentIndex = (childIndex - 1)/2;

            if(pq[childIndex] < pq[parentIndex]){
            // swapping
            int temp = pq[childIndex];
            pq[childIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
            }

            else{
                break;
            }

            childIndex = parentIndex;
        }        
    }
    
    
    int removeMin(){

        if(isEmpty()){
            return -1;  // priority is empty
        }

        int ans = pq[0];

        pq[0] = pq[pq.size()-1];
        pq.pop_back();

        // down heapify

        // compare parent index with leftchildindex, rightchildindex values
        // maintain minindex of children(of small one)

        int parentIndex = 0;
        int leftChildIndex = 2*parentIndex+1;
        int rightChildIndex = 2*parentIndex+2;
        

        while(leftChildIndex < pq.size()){
            int minIndex = parentIndex;

            if(pq[minIndex] > pq[leftChildIndex]){
                minIndex = leftChildIndex;
            }
            if(rightChildIndex < pq.size() && pq[rightChildIndex] < pq[minIndex]){
                minIndex = rightChildIndex;
            }

            if(minIndex == parentIndex){
                break;
            }

            int temp = pq[minIndex];       // swaping minindex and parent
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
            
            parentIndex = minIndex;
            leftChildIndex = 2*parentIndex+1;
            rightChildIndex = 2*parentIndex+2;

        }

        return ans;
    }

};

int main(){
    PriorityQueue p;

    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(67);

    cout<<p.getSize()<<endl;
    cout<<p.getMin()<<endl;
    

    while(!p.isEmpty()){
        cout<<p.removeMin()<<" ";
    }
    cout<<endl;
    
}