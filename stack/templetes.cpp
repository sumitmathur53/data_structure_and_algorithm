#include<iostream>
using namespace std;

template<typename T, typename V>


class pair1{
    T x;
    V y;

    public:
    void setx(T x){
        this->x = x;
    }

    T getx(){
        return x;
    }

    void sety(V y){
        this->y = y;
    }

    V gety(){
        return y;
    }
};

int main(){
    
    pair1<pair1<int,int>,int> p2;

    p2.sety(13);
    pair1<int,int> p3;
    p3.setx(11);
    p3.sety(12);

    p2.setx(p3);

    cout<<p2.getx().getx()<<" "<<p2.getx().gety()<<
                  " "<<p2.gety()<<endl;
}