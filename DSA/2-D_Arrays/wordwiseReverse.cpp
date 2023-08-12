#include <iostream>
#include <cstring>
using namespace std;

void WordReverse(char input[]){
    int length = strlen(input); 
    int i=0,j=length-1;
    while(i<j){
        swap(input[i],input[j]);
        i++; j--;
    }
    for(int i=0;input[i]!='\0';i++){
        for(int j=0;input[j]!=' ';j++){
            swap(input[j],input[length-j-1]);
        }
    }
    cout << input;
}

int main(){
    char input[10^4];
    cout << "Enter string to reverse ";
    cin.getline(input,10^4);
    WordReverse(input);
}
