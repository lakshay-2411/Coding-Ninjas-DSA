#include <iostream>
#include <cmath>
using namespace std;

int keypad(int num,string output[]){
    string input;
    if(num==0){
        output[0] = "";
        return 1;
    }
    int n = num%10;
    num =  num/10;
    int smallAns = keypad(num,output);
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
    int ans_size = smallAns*(input.size());
    string temp[ans_size];
    int k =0;
    for(int i=0;i<smallAns;i++){
        for(int j=0;j<input.size();j++){
            temp[k] = output[i] + input[j];
            k++;
        }
    }
    for(int i=0;i<ans_size;i++){
        output[i] = temp[i];
    }
    return smallAns*input.size();
}

int main(){
    int num;
    cout << "Enter the keypad number " << endl;
    cin >> num;
    int power = pow(floor(log10(num) + 1),4);
    string* output = new string[power];
    int count = keypad(num,output);
    for(int i=0;i<count;i++){
        cout << output[i] << endl;
    }
    delete [] output;
}