#include <iostream>
using namespace std;

int main(){
    int i = 65;
    char c = i;     //Implicit Typecasting
    cout << c << endl;

    int* p  = &i;
    char*pc = (char*)p;    //Explicit Typecasting
    cout << *p << endl;
    cout << *pc << endl;
    // Three of them will gonna print null as integer is stored in such a way(65,0,0,0) so the character pointer(*pc) will read only first byte and everyone else will print null
    cout << *(pc + 1) << endl;
    cout << *(pc + 2) << endl;
    cout << *(pc + 3) << endl;

    cout << p << endl;      //Integer pointer will print the address
    cout << pc << endl;     //Character pointer go to that address and print all the values until it find the null character

}