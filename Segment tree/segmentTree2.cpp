#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class segmentTree{
    public:
    vector<ll> tree;
    segmentTree(ll n){
        tree.resize(4*n);
    }
    void build(vector<ll>&arr,int low, int high, int node){
        if(low==high){
            tree[node]=arr[low];
        }
        int mid=(low+high)/2;
        build(arr,low,mid,node*2);
        build(arr,mid+1,high,node*2+1);
        tree[node]=max(tree[node*2],tree[node*2+1]);
        return;
    }
    ll query(int low,int high,int l,int r){
        
    }

};

int main(){
    int _=1;
    cin>>_;
    while(_--){

    }
    return 0;
}