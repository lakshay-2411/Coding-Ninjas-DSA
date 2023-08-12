#include <iostream>
using namespace std;

class Vehicle{
    private:
    int maxSpeed;\

    protected:
    int numTyres;

    public:
    string color;

    Vehicle(){
        cout << "Vehicle's default constructor called! " << endl;
    }
    void print(){
        cout << "Vehicle " << endl;
    }
    Vehicle(int z){
        cout << "Vehicle's parametrized constructor "<< endl;
        maxSpeed = z;
    }
    ~Vehicle(){
        cout << "Vehicle's destructor " << endl;
    }
};