#include <iostream>
using namespace std;
#include <stack>
#include <queue>

class StackAssign{
    public:
//------------------------------------------REVERSE_STACK-----------------------------------------
    stack<int> reverse(stack<int> s){
    stack<int> ans;
    while(!s.empty()){
        int num = s.top();
        ans.push(num);
        s.pop();
    }
    return ans;
}
//-------------------------------------REVERSE_STACK(RECURSIVELY)----------------------------------
    void insertAtBottom(stack<int> &st,int ele){
        if(st.empty()){
            st.push(ele);
            return;
        }
        int top = st.top();
        st.pop();
        insertAtBottom(st,ele);
        st.push(top);
    }
    void reverseStack(stack<int> &s){
        if(s.empty()){
            return;
        }
        int top = s.top();
        s.pop();
        reverseStack(s);
        insertAtBottom(s,top);
    }
//----------------------------------------REVERSE_QUEUE--------------------------------------------
    void reverseQueue(queue<int> &q){
        if(q.empty()){
            return;
        }
        int frontElement = q.front();
        q.pop();
        reverseQueue(q);
        q.push(frontElement);
    }
//----------------------------------CHECK_REDUNDANT_BRACKETS---------------------------------------    
    bool checkRedundantBrackets(string s){
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                bool foundOperand = false;
                while(!st.empty()&&st.top()!='('){
                    if(st.top()=='+'||st.top()=='-'||st.top()=='*'||st.top()=='/'){
                        foundOperand = true;
                    }
                    st.pop();
                }
                st.pop();
                if(foundOperand == false){
                    return true;
                }
            }else{
                st.push(s[i]);
            }
        }
        return false;
    }
//-------------------------------------STOCK_SPAN---------------------------------------------
    vector<int> stockSpan(int arr[],int n){
        stack<int> s;
        vector<int> ans;
        s.push(0);
        ans.push_back(1);
        for(int i=1;i<n;i++){
            while(!s.empty() && arr[s.top()] <= arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(i+1);
            }else{
                ans.push_back(i-s.top());
            }
            s.push(i);
        }
        return ans;
    }
//----------------------------------MINIMUM_BRACKET_REVERSAL-----------------------------------
    int countRev(string s){
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i] == '{'){
                st.push(s[i]);
            }else{
                if(st.empty()){
                    st.push(s[i]);
                }else if(st.top() != '{'){
                    st.push(s[i]);
                }else{
                    st.pop();
                }
            }
        }
        int count = 0;
        char c1,c2;
        while(!st.empty()){
            c1 = st.top();
            st.pop();
            if(!st.empty()){
                c2 = st.top();
                st.pop();
            }else{
                return -1;
            }
            if(c1 == c2){
                count++;
            }else{
                count += 2;
            }
        }
        return count;
    }
//-------------------------------------VALID_PARENTHESES----------------------------------------
    bool isValidParentheses(string s){
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('||s[i] == '{'||s[i] == '['){
                st.push(s[i]);
            }else if(s[i] == ')'||s[i] == '}'||s[i] == ']'){
                if(st.empty()){
                    return false;
                }
                char top = st.top();
                st.pop();
                if(s[i] == '(' && top != ')'||s[i] == '{' && top != '}'||s[i] == '[' && top != ']'){
                    return false;
                }
            }
        }
        return st.empty();
    }

};

int main(){
    StackAssign st;
    string s = "{{}{{{{}}}}}{}{}{{{{{{{{{}}}}}}}}}";
    cout << st.isValidParentheses(s) << endl;


    /*
    string s = "{{}{{{{}}}}}{}{}{{{{{{{{{}}}}}}}}}";
    cout << st.countRev(s) << endl;
    */
    /*
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    vector<int> ans = st.stockSpan(arr,n);
    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
    */
    /*
    StackAssign St;
    string s = "(a+b)";
    if(St.checkRedundantBrackets(s)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    */
    /*
    StackAssign St;
    stack <int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    St.reverseStack(s);
    cout << s.top();
    */
    /*
    stack<int> ans = St.reverse(s);
    while(!ans.empty()){
        cout << ans.top() << endl;
        ans.pop();
    }
    */
}