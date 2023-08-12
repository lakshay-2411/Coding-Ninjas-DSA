#include <iostream>
using namespace std;


class Car : virtual public Vehicle{
public:

int numGears;

Car() {
cout<< "Car's default constructor " << endl;
}

~Car() {
cout << "Car's Destructor " << endl;
}


void print() {
cout << "NumTyres : " << numTyres << endl;
cout<<"Color : " << color << endl;
cout<<"Num gears : " << numGears << endl; 
// cout << "Max Speed: " << maxSpeed << endl;
}

};

class Truck : virtual public Vehicle {
    public:
    Truck(){
        cout << "Truck's constructor " << endl;
    }
    ~Truck(){
        cout << "Truck's destructor " << endl;

    }
};

class Bus : public Car, public Truck{
    public:
    Bus(){
        cout << "Bus constructor " << endl;
    }
    ~Bus(){
        cout << "Bus destructor " << endl;

    }
    // PRINT is used here to solve ambiguity
/*

    void print(){
        cout << "Bus " << endl;
    }
*/

};
