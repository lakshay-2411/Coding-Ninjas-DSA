#include <iostream>
#include <cstring>
using namespace std;

void reverse(char input[]){
    int length = strlen(input); 
    int i=0,j=length-1;
    while(i<j){
        swap(input[i],input[j]);
        //char temp=input[i];
        //input[i]=input[j];
        //input[j]=temp;
        i++;
        j--;
    }
    cout << input;
}



int main(){
    char input[10^4];
    cout << "Enter string to reverse ";
    cin.getline(input,10^4);
    reverse(input);
}