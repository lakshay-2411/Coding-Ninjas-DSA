#include <iostream>
#include <cmath>
using namespace std;

int subseq(string s,string out[]){
    if(s.empty()){
        out[0] = "";
        return 1;
    }
    int smallsize = subseq(s.substr(1),out);
    for(int i=0;i<smallsize;i++){
        out[i + smallsize] = s[0] + out[i];
    }
    return 2 * smallsize;

}

int main(){
    string s;
    cout << "Enter the string " << endl;
    cin >> s;
    int n = pow(2,s.size());
    string* output = new string[n];
    int count = subseq(s,output);
    for(int i=0;i<count;i++){
        cout << output[i] << endl;
    }
    delete [] output;
}