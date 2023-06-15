#include<iostream>
using namespace std;

#include<unordered_map>
#include<string>
#include<vector>

int main(){
   unordered_map<string, int> ourmap;

   ourmap["abc"] = 1;

   ourmap["abc1"] = 2;
   ourmap["abc2"] = 3;
   ourmap["abc4"] = 4;
   ourmap["abc5"] = 5;

   unordered_map<string,int> :: iterator it = ourmap.begin(); 
   // no particular order

   while(it!=ourmap.end()){
      cout<<"key -> "<<it->first<<" value "<<it->second<<endl;
      it++;
   }

   // find
   //also give iterator
   unordered_map<string,int> :: iterator it2 = ourmap.find("abc");
   ourmap.erase(it2);
   
   vector<int> v;
   v.push_back(1);
   v.push_back(21);
   v.push_back(12);
   v.push_back(111);

   vector<int>::iterator it1 = v.begin();
   while(it1!=v.end()){
      cout<<*it1<<endl;
      it1++;
   }

}