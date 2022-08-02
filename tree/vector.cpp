#include<iostream>
using namespace std;
#include<vector>


int main(){
    vector<int> v;
    vector<int> *vp = new vector<int>(); // dynamic allocation

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    cout<<v.capacity()<<endl; // give the current size of dynamic array

    v[1]=100;
    v[4] = 2332; // if we do this then it will not work as dynamic 
    // not increase the size;
    //

    cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;
    //cout<<v[7]<<endl; // this give garbage 
    cout<<v.at(2)<<endl;  // it will not give value out of range
    cout<<v.at(1)<<endl;  // safer to use at()
    cout<<v.size()<<endl;

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    v.pop_back(); // remove the last element
}