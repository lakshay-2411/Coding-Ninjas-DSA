#include <iostream>
#include "vehicle.cpp"
#include "diamondprob.cpp"
using namespace std;

int main(){
    Bus b;
   // b.print();         // To solve ambiguity firstly we can make print function in bus class then only print
                       // function of bus class will be used 

    // Secondly we can implicitly define that which class of print function we are using

   // b.Car :: print();    // this will give print function of car(if car has print) otherwise of vehicle

    // we have resolved the ambiguity by using above two methods but still two copies of print function
    // are being made
    // so we'll use keyword virtual in both car and truck class

}