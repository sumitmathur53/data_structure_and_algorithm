#include<iostream>
#include<string>
using namespace std;

string getCompressedString(string &input){

    int n = input.size();  // length of input string

    string compressedstring = "";  // to hold the final compressed string

    int localcount = 0;  // to keep the count of repetion of current
                         // charactor of the string
   
    char currentcharactor;   // to store the current charactor

    int i=0,j=0;

    for(i=0;i<n;i++){
        currentcharactor = input[i];
        localcount = 0;

        for(j=i;j<n;j++){

            if(currentcharactor == input[j]){
                localcount++;
            }else{
                break;
            }
        }

        if(localcount==1){
            compressedstring  += currentcharactor;
        }else{
            compressedstring = compressedstring + currentcharactor + to_string(localcount);
        }

        i = j-1;
    }    

    return compressedstring;              

}

int main() {
    int size = 1e6;
    string str;
    getline(cin, str);
    str = getCompressedString(str);
    cout << str << endl;
}
