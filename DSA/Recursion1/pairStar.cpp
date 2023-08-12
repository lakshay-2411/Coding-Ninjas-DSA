#include <iostream>
using namespace std;

string pairStar(string s){
    if(s.length()<=1){
        return s;
    }
    if(s[0]==s[1]){
        s.insert(1,"*");
        return pairStar(s.substr(0));
    }else{
        return s[0] + pairStar(s.substr(1));
    }
}

int main(){
    string s;
    cout << "Enter the string " << endl;
    cin >> s;
    cout << pairStar(s) << endl;
}

        /// METHOD 2 ///
        /*
        string s;
    cin >> s;
    for(int i=0;i<s.length();i++){
        if(s[i]==s[i+1]){
            s.insert(i+1,"*");
        }
    }
    cout << s;
        */