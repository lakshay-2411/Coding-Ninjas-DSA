#include <iostream>
using namespace std;

string replacePI(string s){
    if(s.length()<=1){
        return s;
    }
    if(s[0]=='p' && s[1]=='i'){
        return "3.14" + replacePI(s.substr(2));
    }else{
        return s[0] + replacePI(s.substr(1));
    }
}

int main(){
    string s;
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> s;
        cout << replacePI(s) << endl;
    }
    //cout << "Enter string " << endl;
    //cin >> s;
}


        ///METHOD 2 ///  ///pi with 3.14
        /*
        string replacePI(string s){
    if(s.length()==0 || s.length()==1){
        return s;
    }
    string smallans = replacePI(s.substr(2));
    if(s[0]=='p' && s[1]=='i'){
        return "3.14" + smallans;
    }else{
        return s[0] + replacePI(s.substr(1));
    }
}
        */

       ///METHOD 3///     ///pi with 3.14
       /*
           string S;
    cin >> S;
    string S2 = "3.14";
    for(int i=0;i<S.length();i++){
        if(S[i]=='p' && S[i+1]=='i'){
            S.erase(i,2);
            S.insert(i,S2);
        }
    }
    cout << S;
       */

      /// METHOD 4 ///       ///3.14 with pi

      /*
      int t;
    string s;
    cin >> t;
    for(int i=0;i<t;i++){
        std :: cin >> s;
    string s2 = "pi";
    int j = s.find("3.14");
    s.erase(j,4);
    s.insert(j,s2);
    }
    for(int i=0;i<t;i++){
        std :: cout << s << endl;
    }
      */

     /// METHOD 5 ///        ///3.14 with pi

     /*
     string replace(string s){
    if(s.length()<=1){
        return s;
    }
    if(s[0]=='3'&&s[1]=='.'&&s[2]=='1'&&s[3]=='4'){
        return "pi" + replace(s.substr(4));
    }else{
        return s[0] + replace(s.substr(1)); 
    }
}
     */