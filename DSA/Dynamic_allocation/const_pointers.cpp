#include <iostream>
using namespace std;

void g(int const &a){   //we have declared const here so no way of changing the value, If we want to change the value just pass be reference only
    a++;            //purely a wrong statement
}



void f(const int *a){
    (*a)++;         //can't do this because the path through pointer is constant
}

int main(){
    int const i = 10;   //path through i is constant
//    int *p = &i;    //this line will give error because pointer has the power to change this variable so pointer has to make sure that it will be a const and will not change the variable
//Correct form of above line is
    int const *p = &i;      //read in reverse! p is a pointer to a constant integer
//Now both path becomes constant, we can't make changes through any path



//CONSTANT POINTER WITH NON CONST INTEGER
    int j = 10;
    int *p3 = &j;           //or we don't have to write this by writing next line
    f(p3);                  //or directly pass f(&j)
    g(j);



    int const *p2 = &j;

    cout << *p2 << endl;
    j++;                //can't do (*p2++) as the path through pointer is constant
    cout << *p2 << endl;


}