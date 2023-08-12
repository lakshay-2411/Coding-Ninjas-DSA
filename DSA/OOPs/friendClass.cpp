#include <iostream>
using namespace std;

class Bus{
    public:
    void print();

};

class Truck{
    private:
    int x;

    protected:
    int y;

    public:
    int z;

    friend void Bus :: print();
    friend void test();

};
// if we are making any function a friend of another class then we can't define it in the class
// We have to define this function outside the class 

void Bus :: print(){
    Truck t;
    t.x = 10;
    t.y = 20;
    cout << t.x << " " << t.y << endl;
}

void test(){
    // Access the private properties of Truck
    Truck t1;
    t1.x = 15;
    t1.y = 25;
    cout << t1.x << " " << t1.y << endl;

}


int main(){
    Bus b;
    b.print();
    test();
}