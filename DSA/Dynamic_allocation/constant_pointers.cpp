#include <iostream>
using namespace std;

int main(){
    int i = 10;
    int j = 20;

    int const *p = &i;      //p is a pointer to a constant integer
    //p is promising that it'll not change the integer to what it is pointing
    //but p can change its own value 

    //    (*p)++      don't do this as it'll change value of i

    p = &j;     //therefore we can write this




    //if you want that your pointer must be a constant then,
    int * const p2 = &i;        //p2 is a const pointer to an integer
    (*p2)++;            //now I can do this 
    //one thing I can't do is 
    //      p2 = &j;            //because p2 is a constant pointer





    //
    int const * const p3 = &i;                   //p3 is a const pointer to a const integer
    //now I cannot do any of these two
    //    (*p3)++;
    //  OR    p3 = &j;


}