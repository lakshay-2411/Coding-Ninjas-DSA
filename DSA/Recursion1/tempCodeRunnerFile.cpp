if(s.length()<=0){
        return "";
    }
    if(s[0]=='x'){
        s.erase(0,1);
        return remove(s.substr(0));
    }else{
        return s[0] + remove(s.substr(1));
    }