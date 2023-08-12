#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

string removeDuplicates(string str) {
	    // code here
	string ans;
	unordered_map<char,int> mpp;
	for(int i=0;i<str.length();i++){
	    if(mpp.count(str[i])<1){
	        ans.push_back(str[i]);
	    }
	    mpp[str[i]]++;
	}
	return ans;
}

vector<int> removeDuplicates(int arr[],int size){
    vector<int> output;
    unordered_map<int,bool> map;
    for(int i=0;i<size;i++){
        if(map.count(arr[i]) > 0){
            continue;
        }
        map[arr[i]] = true;
        output.push_back(arr[i]);
    }
    return output;
}

int maxFreqNum(int arr[],int n){
    int maxFreq = 0;
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        if(mpp.count(arr[i])>maxFreq){
            maxFreq = arr[i];
        }
    }
    unordered_map<int,int>::iterator itr;
    for(itr = mpp.begin();itr!=mpp.end();itr++){
        cout << itr->first << '\t' << itr->second;cout << endl;
    }
    return maxFreq;
}

vector<int> arrayIntersection(vector<int> arr1,vector<int> arr2){
    unordered_map<int,int> mpp;
    vector<int> ans;
    for(int i=0;i<arr1.size();i++){
        mpp[arr1[i]]++;
    }
    for(int i=0;i<arr2.size();i++){
        if(mpp.count(arr2[i])>0){
            ans.push_back(arr2[i]);
        }
    }
    return ans;
}

int numPairSumto0(vector<int> arr){
    if(arr.size()==0){
        return 0;
    }
    int number = 0;
    unordered_map<int,int> mpp;
    for(int i=0;i<arr.size();i++){
        int c = -arr[i];
        if(mpp.find(c)!=mpp.end()){
            number += mpp[c];
        }
        mpp[arr[i]]++;
    }
    return number;
}

/*
int longestConsecutiveSequence(vector<int> arr){
    if(arr.size() == 0){
        return 0;
    }
    unordered_map <int,bool> map;
    for(int i=0;i<arr.size();i++){
        map[arr[i]] = true;
    }
    int ans = 0;
    for(int i=0;i<arr.size();i++){
        if(map[arr[i]] != false){
            int c = 1;
            while(map[arr[i]+c]){
                c++;
            }
            ans = max(ans,c);
        }
    }
    return ans;
}
*/

int countKDifference(vector<int>& nums, int k) {
    unordered_map<int,int> m;
	int count = 0;
	for(int i=0;i<nums.size();i++){
	    int num1 = nums[i]+k;
	    int num2 = nums[i]-k;
	    if(m.find(num1)!=m.end()){
	        count += m[num1];
	    }
	    if(m.find(num2)!=m.end() && num1!=num2){
	        count += m[num2];
	    }
	    m[nums[i]]++;
	}
	return count;
}

int longestSubsetZeroSum(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> m;
        int sum = 0;
        int length = 0;
        m[0] = -1;
        for(int i=0;i<n;i++){
            sum += A[i];
            if(m.find(sum) != m.end()){
                length = max(length,i-m[sum]);
            }else{
                m[sum] = i;
            }
        }
        return length;
    }

int main(){
    vector<int> v1 = {2,12,9,16,10,5,3,20,25,11,1,8,6};
    vector<int> v = {4,4,4,4};
    int arr[] = {2,12,2,11,12,2,1,2,2,11,12,2,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << countKDifference(v,0);
    
    
    
    
    //cout << longestConsecutiveSequence(v1);
    
    
    //cout << maxFreqNum(arr,n);


    /*
    vector<int> ans = arrayIntersection(v1,v2);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    */

    // int n = sizeof(arr1)/sizeof(arr1[0]);
    // cout << maxFreqNum(arr1,n);
}