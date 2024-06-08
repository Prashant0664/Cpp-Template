#include<bits/stdc++.h>
using namespace std;
class Segtree{
    public:
    vector<pair<int,int>>arr;
    vector<pair<int,int>>tree;
    Segtree(int n){
        arr.resize(n);
        tree.resize(4*n);
    }
    void fill(vector<int>v){
        for(int i=0;i<arr.size();i++){
            arr[i].first=v[i];
            arr[i].second=v[i];
        }
    }
    void build(int st, int en, int node){
        if(st==en){
            tree[node]=arr[st];
            return;
        }
        int mid=(st+en)>>1;
        build(st,mid,2*node);
        build(mid+1,en,2*node+1);
        tree[node].first=min(tree[2*node].first,tree[2*node+1].first); // change it according to the problem
        tree[node].second=max(tree[2*node].second,tree[2*node+1].second); // change it according to the problem
    }
    pair<int,int> query(int node, int st,int en, int low, int high){
        if(st>high || en<low){
            return {INT_MAX,INT_MIN}; // not in range(do not overlap)
        }
        if(st>=low && en<=high){
            return {tree[node].first,tree[node].second}; // completely in range
        }
        int mid=(st+en)>>1;
        pair<int,int> left=query(2*node,st,mid,low,high);
        pair<int,int> right=query(2*node+1,mid+1,en,low,high);
        return {(int)min(left.first,right.first),(int)max(left.second,right.second)}; // change it according to the problem
    }
};


int main(){
    Segtree s(10);
    vector<int>arr={1,2,99993,411,-9941,0,-999,10,9,10};
    s.fill(arr);
    s.build(0,9,1);
    pair<int,int>p=s.query(1,0,9,4,7);
    cout<<p.first<<' '<<p.second<<endl;
}