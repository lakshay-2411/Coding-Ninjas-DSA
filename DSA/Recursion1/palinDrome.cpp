#include <iostream>
#include <cstring>
using namespace std;

bool check(char input[],int length){
    if(length<=1){
        return true;
    }
    if(input[0] != input[length-1]){
        return false;
    }else{
        check(input+1,length-2);
    }
}

int main(){
    char input[100];
    cout << "Enter string to check " << endl;
    cin >> input;
    int length = strlen(input);
    if(check(input,length)){
        cout << "It is a Palindrome ";
    }else{
        cout << "Not a Palindrome ";
    }
}