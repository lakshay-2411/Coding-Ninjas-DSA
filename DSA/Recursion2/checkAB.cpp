#include <iostream>
using namespace std;

bool check(string s){
    if(s.length()==0){
        return true;
    }
    if(s[0]!='a'){
        return false;
    }
    if(s[1]=='b' && s[2]=='b'){
        return check(s.substr(3));
    }
    return check(s.substr(1));
}

int main(){
    string s;
    cout << "Enter the string " << endl;
    cin >> s;
    int result  = check(s);
    if(result==1) cout << "True";
    else cout << "False";
}