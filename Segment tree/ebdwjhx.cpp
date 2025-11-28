// #include<bits/stdc++.h>
// using namespace std;
// #define pn(x) cout<<x<<endl;
// #define ps(x) cout<<x<<' ';
// #define endo cout<<endl;
// #define printv(v) for(auto x:v){ps(x);}endo;
// #define printve(v) for(auto x:v){ps(x);};
// #define mod 1000000007
// typedef long long int ll;
// int getMid(int s, int e) { return s + (e - s) / 2; }
// int RMQUtil(int* st, int ss, int se, int qs, int qe,
//                                         int index)
// {
//     if (qs <= ss && qe >= se)
//         return st[index];
//     if (se < qs || ss > qe)
//         return 0;
//     int mid = getMid(ss, se);
//     return max(RMQUtil(st, ss, mid, qs, qe, 2 * index + 1),
//             RMQUtil(st, mid + 1, se, qs, qe, 2 * index + 2));
// }
// int RMQ(int* st, int n, int qs, int qe)
// {
//     return RMQUtil(st, 0, n - 1, qs, qe, 0);
// }
// int constructSTUtil(int arr[], int ss, int se, int* st,
//                                             int si)
// {
    
//     if (ss == se) {
//         st[si] = arr[ss];
//         return arr[ss];
//     }
 
//     int mid = getMid(ss, se);
//     st[si] = max(constructSTUtil(arr, ss, mid, st, si * 2 + 1),
//                 constructSTUtil(arr, mid + 1, se, st, si * 2 + 2));
//     return st[si];
// }
// int* constructST(int arr[], int n)
// {
//     int x = (int)(ceil(log2(n)));
 
//     int max_size = 2 * (int)pow(2, x) - 1;
 
//     int* st = new int[max_size];
//     constructSTUtil(arr, 0, n - 1, st, 0);
//     return st;
// }
 
// int maximumOccurrence(int arr[], int n, int qs, int qe)
// {
//     int freq_arr[n + 1];
//     unordered_map<int, int> cnt;
//     for (int i = 0; i < n; i++)
//         cnt[arr[i]]++;
//     for (int i = 0; i < n; i++)
//         freq_arr[i] = cnt[arr[i]];
//     int* st = constructST(freq_arr, n);
//     int maxOcc;
//     if (arr[qs] == arr[qe])
//         maxOcc = (qe - qs + 1);
//     else {
//         int leftmost_same = 0, righmost_same = 0;
//         while (qs > 0 && qs <= qe && arr[qs] == arr[qs - 1]) {
//             qs++;
//             leftmost_same++;
//         }
//         while (qe >= qs && qe < n - 1 && arr[qe] == arr[qe + 1]) {
//             qe--;
//             righmost_same++;
//         }
//         maxOcc = max({leftmost_same, righmost_same,
//                                 RMQ(st, n, qs, qe)});
//     }
//     return maxOcc;
// }
// void solution(){
//     ll n,m;
//     cin>>n;
    
    
//     string s;
    
    
//     vector<ll>v(n);
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//     }
//     return;
// }
// int main(){
//     int _=1;
//     cin>>_;
//     while(_--){
//         solution();
//     }
//     return 0;
// }
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> processQueries(vector<int>& nums, vector<vector<int>>& queries) {
        SegmentTree segTree(nums);
        vector<int> result;
        
        
        
        return result;
    }
};

// Example usage
int main() {
    vector<int> nums = {4,1,4,2,1,5};
    vector<vector<int>> queries = {{2,2,4}, {1,0,2}, {1,0,4}};
    
    Solution sol;
    vector<int> result = sol.processQueries(nums, queries);
    
    for (int res : result) {
        cout << res << " ";
    }
    return 0;
}
