#include <iostream>
using namespace std;

void subseq(string s,string output){
    if(s.empty()){
        cout << output << endl;
        return;
    }
    subseq(s.substr(1),output);
    subseq(s.substr(1),output + s[0]);
}

int main(){
    string s,output;
    cout << "Enter the string " << endl;
    cin >> s;
    subseq(s,output);
}