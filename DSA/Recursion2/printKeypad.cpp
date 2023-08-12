#include <iostream>
using namespace std;

void keypad(int num,string output){
    string input;
    if(num==0){
        cout << output << endl;
        return;
    }
    int n = num%10;
    switch(n){
        case 2: input = "abc";
        break;
        case 3: input = "def";
        break;
        case 4: input = "ghi";
        break;
        case 5: input = "jkl";
        break;
        case 6: input = "mno";
        break;
        case 7: input = "pqrs";
        break;
        case 8: input = "tuv";
        break;
        case 9: input = "wxyz";
        break;
    }
    keypad(num/10,input[0] + output);
    keypad(num/10,input[1] + output);
    keypad(num/10,input[2] + output);
    //keypad()

}

int main(){
    int num;
    cout << "Enter the keypad number " << endl;
    cin >> num;
    string output;
    keypad(num,output);
}