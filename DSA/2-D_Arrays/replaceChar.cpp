#include <iostream>
using namespace std;
void change(char input[],char c1,char c2){
    for(int i=0;input[i]!='\0';i++){
        if(input[i]==c1){
            input[i]=c2;
        }
    }
    cout <<"updated string is " << input;
}
int main(){
    char input[10^4];
    char c1,c2;
    cout << "Enter string ";
    cin >> input;
    cout << "Enter c1 ";
    cin >> c1;
    cout << "Enter c2 ";
    cin >> c2;
    change(input,c1,c2);
}