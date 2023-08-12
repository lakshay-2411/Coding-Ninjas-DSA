#include <iostream>
using namespace std;


void remove(char s[]){
    if(s[0] == '\0'){
        return;
    }
    if(s[0] != s[1]){
        remove(s+1);
    }else{
        int i = 1;
        for(;s[i] != '\0';i++){
            s[i-1] = s[i];
        }
        s[i-1] = s[i];
        remove(s);
    }
}


    /// METHOD 2 ///
    /*
string removeConsecutiveCharacter(string s){        
    if(s[0] == '\0'){
        return "";
    }
    if(s[0] == s[1]){
        s.erase(0,1);
        return removeConsecutiveCharacter(s.substr(0));
    }else{
        return s[0] + removeConsecutiveCharacter(s.substr(1));
    }
}
*/
        

int main(){
    char s[100];
    cout << "Enter the string " << endl;
    cin >> s;
    remove(s);
    //cout << removeConsecutiveCharacter(s);
    cout << s;
}
