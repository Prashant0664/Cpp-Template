#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node*root;
    bool flag=0;
    Node*list[256];
    bool contains(char ch){
        return list[ch-'0'];
    }
    void put(char ch,Node*node){
        list[ch-'0']=node;
    }
    Node* next(char ch){
        return list[ch-'0'];
    }
    void setEnd(){
        flag=1;
    }
};
class Trie{
    Node *root;
    public:
    void insert(std::string s){
        int len=s.length();
        Node*temp=root;
        for(int i=0;i<len;i++){
            char ch=s[i];
            if(!temp->contains(ch)){
                temp->put(ch,new Node());
            }
            temp=temp->next(ch);
        }
        temp->setEnd();
    }
    std::string toBinary(int n){
        std::string s;
        for(int m = sizeof(n) * 8;m--;){
            s.push_back('0'+((n >> m) & 1));
        }
        if(s.length()<32){
            std::string sample="";
            for(int i=s.length();i<=32;i++){
                sample+="0";
            }
            sample+=s;
            cout<<"Binary of "<<n<<"\n";
            cout<<sample<<endl;
            return sample;
        }
        cout<<"Binary of "<<n<<"\n";
        cout<<s<<endl;
        return s;
    }
    Trie(vector<int>arr){
        root=new Node();
        for(int i=0;i<arr.size();i++){
            std::string s=toBinary(arr[i]);
            insert(s);
        }
    }
    std::string maxnum(std::string s){
        int n=s.length();
        Node*temp=root;
        std::string ans="";
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='1'){
                if(temp->contains('0')){
                    ans+="0";
                    temp=temp->next('0');
                }
                else{
                    ans+="1";
                    temp=temp->next('1');
                }
            }
            else{
                if(temp->contains('1')){
                    ans+="1";
                    temp=temp->next('1');
                }
                else{
                    ans+="0";
                    temp=temp->next('0');
                }
            }
        }
        return ans;
    }
    
    std::string xors(int n){
        std::string s=toBinary(n);
        cout<<"Binary: "<<endl;
        cout<<s<<endl;
        std::string ans=maxnum(s);
        cout<<"ANS: "<<endl;
        cout<<ans<<endl;
        return ans;
    }
    


};
int maximumXor(vector<int> A)
{
    std::string ans="";
    for(int i=0;i<32;i++){
        ans+="0";
    }
      Trie trie(A);
      for(int i=0;i<A.size();i++){
        std::string s=trie.xors(A[i]);
        std::string ss=trie.toBinary(A[i]);
            ans=max(ans,s);
      }
      int i = stoi(ans, nullptr, 2);
      return i;
}
int main(){
    vector<int>A={5,4,8,17,6,15,6};
    cout<<maximumXor(A);
}