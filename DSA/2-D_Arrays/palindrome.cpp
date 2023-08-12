#include <iostream>
#include <cstring>
using namespace std;
int palindrome(char input[]){
    int length = strlen(input);
    bool found = false;
    for(int i=0;i<length/2;i++){
        if(input[i]!=input[length-i-1]){
            found = true;
            break;
        }
    }
    if(found==true)
    cout << "Not a palindrome ";
    else
    cout << "It is a palindrome ";
}
int main(){
    char input[10^4];
    cout << "Enter string to check : ";
    cin >> input;
    palindrome(input);
}