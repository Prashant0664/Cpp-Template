void split_str(string s,vector<string>&v){
    string temp="";
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            v.push_back(temp);
            temp="";
        }
        else{
            temp+=s[i];
        }
    }
    v.push_back(temp);
}