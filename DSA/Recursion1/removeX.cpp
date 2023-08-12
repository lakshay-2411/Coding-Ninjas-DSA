#include <iostream>
using namespace std;

string remove(string s){
    if(s.length()<=0){
        return "";
    }
    if(s[0]=='x'){
        s.erase(0,1);
        return remove(s.substr(0));
    }else{
        return s[0] + remove(s.substr(1));
    }
}

int main(){
    string s;
    cout << "Enter the string " << endl;
    cin >> s;
    cout << remove(s) << endl;
}


        /// METHOD 2 ///
/*
    void removeX(char s[]){
    if(s[0]=='\0'){
        return;
    }
    if(s[0]!='x'){
        removeX(s+1);
    }else{
        int i =1;
        for(;s[i]!='\0';i++){
            s[i-1] = s[i];
        }
        s[i-1] = s[i];
        removeX(s);
    }
}

*/    
