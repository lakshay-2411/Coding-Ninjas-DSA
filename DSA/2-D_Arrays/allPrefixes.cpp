#include <iostream>
#include <cstring>
using namespace std;

void allPrefixes(char input[]){
    int len = strlen(input);
    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++){
            for(int k=i;k<j+1;k++){
                cout << input[k];
            }
            cout << endl;
        }
    }
}

int main(){
    char input[10^4];
    cout << "Enter string : ";
    cin >> input;
    allPrefixes(input);
}