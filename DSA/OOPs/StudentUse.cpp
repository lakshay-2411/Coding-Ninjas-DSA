#include <iostream>
using namespace std;

class Student{
    public:
    int rollNumber;
    private:
    int age;

    public:
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
int main(){
    // Creating objects statically
    Student s1;
    Student s2;
    Student s3,s4,s5;
    //s1.age = 24;
    s1.rollNumber = 101;
    cout << "S1's Age " << s1.getAge() << endl;
    cout << "S1's Rollnumber " << s1.rollNumber << endl;

    s1.display();
    s2.display();

        //  WE HAVE TO MAKE OUR FUNCTIONS PUBLIC SO THAT THE OBJECTS CAN USE THIS IN MAIN FUNCTION


    // Creating objects dynamically
    Student *s6 = new Student;
  //  (*s6).age = 25;
    (*s6).rollNumber = 104; 
    (*s6).display();

    cout << "S6's Age " << s6 -> getAge() << endl;
    // We can write above two lines in this way also
  //  s6 -> age = 25;
    s6 -> rollNumber = 198;
    s6 -> display();
}