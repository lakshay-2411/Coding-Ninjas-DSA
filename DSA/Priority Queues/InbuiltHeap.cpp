#include <iostream>
#include <queue>
using namespace std;

int main(){
    //MIN HEAP
    priority_queue<int, vector<int>, greater<int>> p;

    p.push(100);
    p.push(21);
    p.push(7);
    p.push(165);
    p.push(78);
    p.push(4);

    cout << p.size() << endl;
    cout << p.empty() << endl;
    cout << p.top() << endl;

    while(!p.empty()){
        cout << p.top() << " ";
        p.pop();
    }




    //MAX HEAP

/*
    priority_queue<int> pq;

    pq.push(100);
    pq.push(21);
    pq.push(7);
    pq.push(165);
    pq.push(78);
    pq.push(4);

    cout << pq.size() << endl;
    cout << pq.empty() << endl;
    cout << pq.top() << endl;

    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }

*/    
}