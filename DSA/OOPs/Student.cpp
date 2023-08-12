#include <iostream>
using namespace std;

class Student{
    public:
    int rollNumber;
    private:
    int age;

    public:

            // DEFAULT DESTRUCTOR
    ~Student(){
        cout << "Default destructor called !" << endl;
    }



    // Default Constructor
    Student(){
         cout << "Default Constructor called!" << endl;
    }


    // Parametrized Constructor 
    Student(int rollNumber ){
        cout << "Parametrized Constructor called!" << endl;
    /**   rollNumber = r;   */

    //  WE CAN WRITE ABOVE LINES AS THIS ALSO

        this -> rollNumber = rollNumber;

    }


    Student(int a,int r){     //This keyword holds the address of current object and is known as pointer variable
    /*    cout << "this " << this << endl;
        cout << "Another Parametrized Constructor called!" << endl;
        rollNumber = r;
        age = a;
        */

        //  WE CAN WRITE ABOVE LINES AS THIS ALSO

        cout << "Another Parametrized Constructor called!" << endl;
        this -> rollNumber = r;
        this -> age = a;
    }



    void display(){
        cout << age << " " << rollNumber << endl;
    }
    int getAge(){
        return age;
    }
    void setAge(int a){
        age = a;
    }


};