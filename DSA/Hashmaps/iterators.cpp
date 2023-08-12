#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    unordered_map<string,int> mpp;
    mpp["abc"] = 1;
    mpp["abc1"] = 2;
    mpp["abc2"] = 3;
    mpp["abc3"] = 4;
    mpp["abc4"] = 5;
    mpp["abc5"] = 6;
    unordered_map<string,int>::iterator it = mpp.begin();
    while(it != mpp.end()){

        //As map is in the form of pair but in "it" we have addresses so we will use it->first 
        //and it->second to print the value

        cout << "Key : " << it->first << " Value : " << it->second << endl;
        it++;
    }

    //-----------------FIND_FUNCTION----------------------

    /*Find function will us the address where "abc" is there and all the values ahead of "abc"*/

    unordered_map<string,int>::iterator it2 = mpp.find("abc");
    while(it2 != mpp.end()){
        cout << "Key : " << it2->first << " Value : " << it2->second << endl;
        it2++;
    }

    //------------------ERASE_FUNCTION-------------------------
    /*Erase functions takes the key as input and delete it from the map*/
    /*We can also give iterator to erase function and where the iterator will pointing it will
    delete that*/
    mpp.erase(it2);

    



    //----------------ITERATORS_FOR_VECTORS---------------------------------------
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    vector<int>::iterator it1 = v.begin();
    while(it1 != v.end()){
        cout << *it1 << endl;           //As it is storing addresses of elements
        it1++;
    }
    v.erase(it1,it1+3);
}