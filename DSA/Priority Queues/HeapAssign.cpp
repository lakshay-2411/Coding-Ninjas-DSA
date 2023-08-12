#include <iostream>
#include <queue>
using namespace std;

void kSortedArray(int input[],int n,int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }
    int j = 0;
    for(int i=k;i<n;i++){
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }

    while(!pq.empty()){
        input[j] = pq.top();
        pq.pop();
        j++;
    }
}

vector<int> kSmallestElements(int arr[],int n,int k){
    priority_queue<int> pq;
    vector<int> ans;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        int top = pq.top();
        if(arr[i] < top){
            pq.pop();
            pq.push(arr[i]);
        }else{
            continue;
        }
    }
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

vector<int> kLargestElements(int arr[],int n,int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        int top = pq.top();
        if(arr[i] > top){
            pq.pop();
            pq.push(arr[i]);
        }else{
            continue;
        }
    }
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

bool isMaxHeap(int a[], int n){
    // Your code goes here
    for(int i=0;i<n;i++){
        int l = 2*i+1;
        int r = 2*i+2;
        if(a[i] > max(a[l],a[r])){
            continue;
        }else{
            return false;
        }
    }
    return true;
}

int KthLargest(int arr[],int n,int k){
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    while(k>1){
        pq.pop();
        k--;
    }
    return pq.top();
}


int main(){
    int input[] = {2,6,10,11,13,4,1,20};
    int k = 4;
    cout << KthLargest(input,8,k);
}