#include <iostream>
using namespace std;
                // STATIC MEMBERS CAN ACCESS ONLY THE STATIC PROPERTIES
class Student{
    static int totalStudents;  // now this is the property of class only
    public:

    int rollNumber;
    int age;


    Student(){
        totalStudents++;
    }
    int getrollNumber() {
        return rollNumber;
    }
    static int gettotalStudents() {            // static function
        return totalStudents;
    }



};
 // WE CAN'T INITIALIZE THE STATIC MEMBERS IN THE CLASS OR IN THE MAIN
    int Student :: totalStudents = 0;   // initialize the static members

int main(){
    /*

    Student s1;
    cout << s1.age << " " << s1.rollNumber << endl;
    cout << s1.totalStudents << endl;    // Error will not come but this is logically a wrong statement
    cout << Student :: totalStudents << endl;

    */ 

   /*
   Student s1;
   Student s2;
   Student s3,s4,s5;
   cout << Student :: totalStudents << endl;
   */
   Student s1;
   Student s2;
   Student s3,s4,s5;
   cout << Student :: gettotalStudents() << endl;


}