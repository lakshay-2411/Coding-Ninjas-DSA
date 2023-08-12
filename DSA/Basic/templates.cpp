#include <iostream>
using namespace std;

/*
template <typename T>

class Pair{
    T x;
    T y;
    public:
    void setX(T x){
        this -> x = x;
    }
    T getX(){
        return x;
    }
    void setY(T y){
        this -> y = y;
    }
    T getY(){
        return y;
    }
};
*/

//IF WE WANT TO MAKE X OF ONE TYPE AND Y OF ANOTHER THEN USE THIS <typename T, typename V>
template <typename T,typename V>

class Pair{
    T x;
    V y;
    public:
    void setX(T x){
        this -> x = x;
    }
    T getX(){
        return x;
    }
    void setY(V y){
        this -> y = y;
    }
    V getY(){
        return y;
    }
};

//FOR TRIPLETS WE CAN USE T,V AND W FOR MAKING TRIPLET CLASS