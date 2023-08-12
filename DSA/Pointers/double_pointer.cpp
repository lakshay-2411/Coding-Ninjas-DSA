// Pointers which store address of other pointers
#include <iostream>
using namespace std;

void increment1(int** p){   //It will make the changes in the copy function and not in the main function,so no changes will be reflected
    p = p + 1;
}
void increment2(int** p){   //It will make changes in the address of *p,so changes will be reflected
    *p = *p + 1;
}
void increment3(int** p){   //It will make changes in the integer value directly,so chnages will be reflected
    **p = **p + 1;
}

int main(){
    int i = 10;
    int* p = &i;
    int** p2 = &p;
    cout << **p2 << endl;
    increment1(&p);
    cout << **p2 << endl;
    increment2(&p);
    cout << **p2 << endl;
    increment3(&p);
    cout << **p2 << endl;



   /* 
    int i= 10;
    int* p = &i;
    int ** p2 = &p;
    cout << p2 << endl;    //Address of p
    cout << &p << endl;    //Address of p

    cout << p << endl;     //Written inside p(address of i)
    cout << *p2 << endl;   //Written inside p(address of i)
    cout << &i << endl;

    cout << i << endl;
    cout << *p << endl;
    cout << **p2 << endl;
    */
}