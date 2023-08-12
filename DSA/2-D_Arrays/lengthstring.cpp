#include <iostream>
using namespace std;

int length(char input[]){
    int count =0;
    for(int i=0;input[i]!='\0';i++){
        count++;
    }
    return count;
}

int main(){
    char input[10^4];
    cout<< "Enter string ";
    cin.getline(input,10^4);
    cout << "Length is " << length(input);
}