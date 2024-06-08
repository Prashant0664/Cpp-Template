#include<bits/stdc++.h>
using namespace std;

// here node represent starting node
// if it is first then tree start from 1 index and we will take node*2 and node*2+1
// if it 0 tree start from 0 index and we will take node*2+1 and node*2+2

// low represent starting index of the array on which operation has to be applied
// high represent ending index of the array on which operation has to be applied

// st represent starting of the array i.e. from 0 to n-1;
// en represent ending of the array i.e. from 0 to n-1;

// comment out lazy in fill for range update


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
    void build(int st, int en, int node){
        if(st==en){
            tree[node]=arr[st];
            return;
        }
        int mid=(st+en)>>1;
        build(st,mid,2*node);
        build(mid+1,en,2*node+1);
        tree[node]=tree[2*node]+tree[2*node+1]; // change it according to the problem
    }
    int query(int node, int st,int en, int low, int high){
        if(st>high || en<low){
            return 0; // not in range(do not overlap)
        }
        if(st>=low && en<=high){
            return tree[node]; // completely in range
        }
        int mid=(st+en)>>1;
        int left=query(2*node,st,mid,low,high);
        int right=query(2*node+1,mid+1,en,low,high);
        return left+right; // change it according to the problem
    }
    void pointUpdate(int node,int ind,int val,int st, int en){
        if(st==en){
            tree[node]+=val; // change it according to the problem like +-/...
            tree[st]+=val; // change it according to the problem like +-/...
            return;
        }
        int mid=(st+en)>>1;
        if(ind<=mid && ind>=st){
            pointUpdate(2*node,ind,val,st,mid);
        }
        else{
            pointUpdate(2*node+1,ind,val,mid+1,en);
        }
        tree[node]=tree[2*node]+tree[2*node+1]; // change it according to the problem
    }
    void rangeUpdate(int node,int st,int en,int low,int high, int val){
        if(lazy[node]!=0){
            tree[node]+=(en-st+1)*lazy[node];
            if(st!=en){
                lazy[2*node]+=lazy[node];
                lazy[2*node+1]+=lazy[node];
            }
            lazy[node]=0;
        }
        if(high<st || low>en || st>en){
            return;
        }
        if(st>=low && en<=high){
            tree[node]+=(en-st+1)*val;
            if(st!=en){
                lazy[2*node]+=val;
                lazy[2*node+1]+=val;
            }
            return;
        }
        int mid=(st+en)>>1;
        rangeUpdate(2*node,st,mid,low,high,val);
        rangeUpdate(2*node+1,mid+1,en,low,high,val);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
    int lazysum(int node, int st,int en, int low, int high){
        if(lazy[node]!=0){
            tree[node]+=(en-st+1)*lazy[node];
            if(st!=en){
                lazy[2*node]+=lazy[node];
                lazy[2*node+1]+=lazy[node];
            }
            lazy[node]=0;
        }
        if(st>high || en<low || st>en){
            return 0; // not in range(do not overlap)
        }
        if(st>=low && en<=high){
            return tree[node]; // completely in range
        }
        int mid=(st+en)>>1;
        return lazysum(2*node,st,mid,low,high)+
                lazysum(2*node+1,mid+1,en,low,high);
    }
};

int main(){
    // Segtree s(10);
    // vector<int>arr={1,2,3,4,5,6,7,8,9,10};
    // s.fill(arr);
    // s.build(0,9,1);
    // s.query(1,0,9,4,7);
}