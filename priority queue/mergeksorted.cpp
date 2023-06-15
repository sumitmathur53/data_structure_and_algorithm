#include<iostream>
using namespace std;

#include<queue>
#include<vector>

#define ppi pair<int,pair<int,int>>

vector<int> merge(vector<vector<int>> arr){

    vector<int> ans;

    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;

    for(int i=0;i<arr.size();i++){
        pq.push({arr[i][0] , {i,0}});
    }

    while(!pq.empty()){
        ppi current_elemnt = pq.top();
        pq.pop();

        int i = current_elemnt.second.first;   // second element from current_element
        int j = current_elemnt.second.second;  //third element from current_element
        
        ans.push_back(current_elemnt.first);

        if(j+1 < arr[i].size()){
            pq.push({arr[i][j+1],{i,j+1}});
        }
    }

    return ans;
}

int main()
{
    // Change n at the top to change number
    // of elements in an array
    vector<vector<int> > arr{ { 2, 6, 12 },
                            { 1, 9 },
                            { 23, 34, 90, 2000 } };
 
    vector<int> output = merge(arr);
 
    cout << "Merged array is " << endl;
    for (auto x : output)
        cout << x << " ";
 
    return 0;
}