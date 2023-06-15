#include<iostream>
using namespace std;
#include<vector>
#include<climits>

class PriorityQueue{
    public:

    PriorityQueue(){

    }

    vector<int> pq;

    int getSize(){
        return pq.size();
    }

    bool isEmpty(){
        return pq.size()==0;
    }

    int getMax(){
        if(pq.size()==0){
            return INT_MIN;
        }
        return pq[0];
    }

    void insert(int element){

        pq.push_back(element);

        int childIndex = pq.size()-1;

        while(childIndex > 0){
            int parentIndex = (childIndex-1)/2;

            if(pq[parentIndex] > pq[childIndex]){
                return;
            }

            int temp = pq[childIndex];
            pq[childIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            childIndex = parentIndex;
        }
    }

    int removeMax(){
        if(pq.size()==0){
            return INT_MIN;
        }

        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();

        int parentIndex = 0;
        int leftChildIndex = parentIndex*2+1;
        int rightChildIndex = parentIndex*2+2;

        while(leftChildIndex < pq.size()){

            int maxIndex = parentIndex;

            if(pq[leftChildIndex] > pq[maxIndex]){
                maxIndex = leftChildIndex;
            }

            if(rightChildIndex < pq.size() && pq[rightChildIndex] > pq[maxIndex]){
                maxIndex = rightChildIndex;
            }

            if(maxIndex == parentIndex){
                break;
            }

            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = maxIndex;
            leftChildIndex = parentIndex*2+1;
            rightChildIndex = parentIndex*2+2;
        }
        return ans;
    }




};