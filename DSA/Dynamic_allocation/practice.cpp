#include <iostream>
using namespace std;

int main(){
    char c = 'A';
    int i = c;
    cout << i << endl;

    char* pc = &c;
    int* p = (int*)pc;
    cout << *p << endl;
    cout << *pc << endl;

    cout << *(pc + 1) << endl;
    cout << *(pc + 2) << endl;
    cout << *(pc + 3) << endl;
    
}