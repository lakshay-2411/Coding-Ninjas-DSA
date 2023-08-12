#include <iostream>
using namespace std;

void replace(char s[],char c1,char c2){
    if(s[0] == '\0'){
        return;
    }
    if(s[0] == c1){
        s[0] = c2;
        replace(s+1,c1,c2);
    }else{
        replace(s+1,c1,c2);
    }
}

int main(){
    char str[100];
    char c1,c2;
    cout << "Enter the string " << endl;
    cin >> str;
    cout << "Enter character 1 " << endl;
    cin >> c1;
    cout << "Enter character 2 " << endl;
    cin >> c2;
    replace(str,c1,c2);
    cout << str;
}