#include<bits/stdc++.h>
using namespace std;
#define pn(x) cout<<x<<endl;
#define ps(x) cout<<x<<' ';
#define endo cout<<endl;
#define printv(v) for(auto x:v){ps(x);}endo;
#define printve(v) for(auto x:v){ps(x);};
#define mod 1000000007
typedef long long int ll;

class Node{
    public:
    Node*lists[26];
    void put(Node*node,char c){
        lists[c-'a']=node;
    }
};

class Trie{
    Node*root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node*temp=root;
        for(auto &i:word){
            if(!temp->lists[i-'a']){
                temp->put(new Node(),i);
            }
            temp=temp->lists[i-'a'];
        }
    }
};


int main(){
    
}