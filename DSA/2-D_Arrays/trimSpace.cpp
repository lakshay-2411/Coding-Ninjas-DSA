#include <iostream>
#include <cstring>
using namespace std;

void trimSpace(char input[]){
    int length = strlen(input);
    int i=0,j;
    for(i=0;i<length;i++){
        if(input[i]==' '){
            for(j=i;j<length;j++)
                input[j]=input[j+1];
                length--;
        }
    }
}

int main(){
    char input[10^4];
    cout << "Enter string : ";
    cin.getline(input,10^4);
    trimSpace(input);
    cout << input;
}