#include<iostream>
using namespace std;
#include<queue>
#include<vector>

class node1{
    public:
    int data;
    int row;
    int col;

    node1(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }

};

class compare{
    public:
    bool operator()(node1* a, node1* b){
        return a->data > b->data;
    }
};


vector<int> mergeKSortedArrays(vector<vector<int>> input) {

    priority_queue<node1* , vector<node1*>, compare> minheap;
    int k = input.size();

    // step 1; insert first element of k sorted array

    for(int i=0;i<k;i++){
        node1* temp = new node1(input[i][0],i,0);
        minheap.push(temp);
    }

    vector<int> ans;

    // step 2

    while(minheap.size()>0){
        node1* temp = minheap.top();

        ans.push_back(temp->data);
        minheap.pop();

        int row = temp->row;
        int col = temp->col;

        if(col+1 < (input[row].size())){
            node1* next = new node1(input[row][col+1],row,col+1);
            minheap.push(next);
        }
    }


    return ans;

}