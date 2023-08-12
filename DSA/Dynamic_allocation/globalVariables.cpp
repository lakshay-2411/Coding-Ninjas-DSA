        //It is loooking good that it is making things easy for us but NEVER use this
        //Biggest problem is that anyone can change it.



#include <iostream>
using namespace std;

//If you want a variable to be shared by everybody just initialize it here and it will be known as global variable
int a;

void g(){
    a++;
    cout << a << endl;
}
void f(){
    cout << a << endl;
    a++;
    g();
}

int main(){
    a = 10;
    f();
    cout << a << endl;
}