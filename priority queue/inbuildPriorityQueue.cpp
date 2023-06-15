#include<iostream>
using namespace std;
#include<queue>

int main(){
    priority_queue<int> pq;

    pq.push(167);
    pq.push(123);
    pq.push(34);
    pq.push(1313);

    cout<<pq.size()<<endl;
    cout<<pq.top()<<endl;

    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
}