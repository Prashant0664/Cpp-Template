/*
       ___      _      ___     ____   _    _   ____     _____  
      |_  |    / \    |_ _|   / ___| | |  | | |  _ \   |_   _| 
        | |   / _ \    | |    \___ \ | |__| | | |_) |    | |   
    |___| |  / ___ \   | |     ___) ||  __  | |  _ <    _| |_  
    |_____| /_/   \_\ |___|   |____/ |_|  |_| |_|  \_\ |_____|

                  ____         _      __  __ 
                 |  _ \       / \    |  \/  |
                 | |_) |     / _ \   | \  / |
                 |  _ <     / ___ \  | |\/| |
                 |_|  \_\  /_/   \_\ |_|  |_|

*/
#include<bits/stdc++.h>
using namespace std;
#define pn(x) cout<<x<<endl;
#define ps(x) cout<<x<<' ';
#define endo cout<<endl;
#define printv(v) for(auto x:v){ps(x);}endo;
#define printve(v) for(auto x:v){ps(x);};
#define mod 1000000007
#define pll pair<ll,ll>
#define pii pair<int,int>
typedef long long int ll;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

class Segtree{
    public:
    vector<int>arr;
    vector<int>tree;
    vector<int>lazy;
    Segtree(int n){
        arr.resize(n);
        tree.resize(4*n,0);
        // lazy.resize(4*n,0); //for range update
    }
    void fill(vector<int>v){
        arr=v;
    }
    void build(int st, int en, int node, int level=0){
        if(st==en){
            tree[node]=arr[st];
            return;
        }
        int mid=(st+en)>>1;
        build(st,mid,2*node, level+1);
        build(mid+1,en,2*node+1, level+1);
        if(level%2==0){
            tree[node]=tree[2*node]|tree[2*node+1]; // change it according to the problem
        }
        else{
            tree[node]=tree[2*node]^tree[2*node+1]; // change it according to the problem
        }
    }

    void pointUpdate(int node,int ind,int val,int st, int en, int level=0){
        if(st==en){
            tree[node]=val; // change it according to the problem like +-/...
            tree[st]=val; // change it according to the problem like +-/...
            return;
        }
        int mid=(st+en)>>1;
        if(ind<=mid && ind>=st){
            pointUpdate(2*node,ind,val,st,mid, level+1);
        }
        else{
            pointUpdate(2*node+1,ind,val,mid+1,en, level+1);
        }
        if(level%2==0){
            tree[node]=tree[2*node]|tree[2*node+1]; // change it according to the problem
        }
        else{
            tree[node]=tree[2*node]^tree[2*node+1]; // change it according to the problem
        }
    }
};


void solution(){
    ll n,m;
    cin>>n;
    cin>>m;
    Segtree seg(1<<n+1);
    vector<int>v(1<<n);
    for(int i=0;i<(1<<n);i++){
        cin>>v[i];
    }
    seg.fill(v);
    seg.build(0,(1<<n)-1,1);
    // cout<<seg.query(1,0,(1<<n)-1,0,(1<<n)-1)<<endl;
    // from 0th index to 2rd index
    // cout<<seg.query(1,0,(1<<n)-1,0,2)<<endl;
    for(int i=0;i<m;i++){
        int p,b;
        cin>>p>>b;
        seg.pointUpdate(1,p-1,b,0,(1<<n)-1);
        // cout<<seg.query(1,0,(1<<n)-1,0,(1<<n)-1)<<endl;
        cout<<seg.tree[1]<<endl;
        // cout<<seg.tree[1]<<endl;
    }
    return;
}
int main(){
    int _=1;
    // cin>>_;
    while(_--){
        solution();
    }
    return 0;
}