#include <iostream>
using namespace std;

int count(string s){
    if(s[0]=='\0'){
        return 0;
    }
    return 1 + count(s.substr(1));
}

int main(){
    string s;
    cin >> s;
    cout << count(s);


    
    // int count = 0;
    // for(int i=0;s[i]!='\0';i++){
    //     count++;
    // }
    // cout << count;
}