#include <iostream>
using namespace std;

class Student {
    public:
    int age;
    const int rollNumber;
    int &x;                 //x is the reference variable of age

    Student(int r,int a) : rollNumber(r), age(a), x(this -> age) {
    }
};

int main(){
    Student s1(2004,24);

}
