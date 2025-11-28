#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution
{
public:
    vector<pair<ll, ll>> tree;
    vector<ll> arr;
    void build(ll low, ll high, ll node)
    {
        if (low == high)
        {
            tree[node].first = arr[low] % (1000000007);
            tree[node].second = 1;
            return;
        }
        ll mid = (low + high) / 2;
        build(low, mid, 2 * node);
        build(mid + 1, high, 2 * node + 1);
        if (tree[2 * node].first < tree[2 * node + 1].first)
        {
            tree[node].first = tree[2 * node].first;
            tree[node].second = tree[2 * node].second;
        }
        else if (tree[2 * node].first > tree[2 * node + 1].first)
        {
            tree[node].first = tree[2 * node + 1].first;
            tree[node].second = tree[2 * node + 1].second;
        }
        else
        {
            tree[node].first = tree[2 * node].first;
            tree[node].second = (tree[2 * node].second % (1000000007) + tree[2 * node + 1].second % (1000000007)) % (1000000007);
        }
        return;
    }
    pair<ll, ll> query(ll node, ll l, ll r, ll low, ll high)
    {
        if (low > r || high < l)
        {
            return {1e9 + 7, -1};
        }
        else if (low >= l && high <= r)
        {
            return tree[node];
        }
        else
        {
            pair<ll, ll> a = query(node * 2, l, r, low, (high + low) / 2);
            pair<ll, ll> b = query(node * 2 + 1, l, r, (low + high) / 2 + 1, high);
            if (a.first > b.first)
            {
                return b;
            }
            else if (a.first < b.first)
            {
                return a;
            }
            else
            {
                return {a.first, (a.second % (1000000007) + b.second % (1000000007)) % (1000000007)};
            }
        }
    }

    void update(ll node, ll value, ll l, ll r)
    {
        if (l == r)
        {
            arr[l] = value % (1000000007);
            tree[node].first = value % (1000000007);
            tree[node].second = 1;
            // cout<<"_"<<l<<" "<<arr[l]<<"_"<<endl;
            return;
        }
        ll mid = (l + r) / 2;
        if (l <= mid)
        {
            update(2 * node, value, l, mid);
        }
        else
        {
            update(2 * node + 1, value, mid + 1, r);
        }
        if (tree[2 * node].first < tree[2 * node + 1].first)
        {
            tree[node].first = tree[2 * node].first;
            tree[node].second = tree[2 * node].second;
        }
        else if (tree[2 * node].first > tree[2 * node + 1].first)
        {
            tree[node].first = tree[2 * node + 1].first;
            tree[node].second = tree[2 * node + 1].second;
        }
        else
        {
            tree[node].first = tree[2 * node].first;
            tree[node].second = ((tree[2 * node].second) % (1000000007) + tree[2 * node + 1].second % (1000000007)) % (1000000007);
        }
        return;
    }
};

int main()
{
    ll n, m;
    cin >> n >> m;
    Solution sol;
    sol.arr.resize(n);
    sol.tree.resize(4 * n);
    for (ll i = 0; i < n; i++)
    {
        cin >> sol.arr[i];
    }
    sol.build(0, n - 1, 1);
    while (m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            // sol.update(b,c,0,n-1);
            // cout<<"="<<arr[b]<<endl;
            sol.arr[b] = c;
            sol.build(0, n - 1, 1);
        }
        else
        {
            pair<ll, ll> ans = sol.query(1, b, c, 0, n - 1);
            cout << ans.first << " " << ans.second << endl;
        }
    }
    // cout<<endl;
    //     for(auto i:sol.arr){
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    // cout<<sol.arr[0];
    return 0;
}

// #include <vector>
// using namepsace std
// class SegmentTree {
// private:
//     std::vector<ll> tree;
//     int n;

//     void build(const std::vector<int>& nums, int node, int start, int end) {
//         if (start == end) {
//             tree[node] = nums[start];
//         } else {
//             int mid = (start + end) / 2;
//             build(nums, 2 * node + 1, start, mid);
//             build(nums, 2 * node + 2, mid + 1, end);
//             tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
//         }
//     }

//     int query(int node, int start, int end, int left, int right) {
//         if (left > end || right < start) {
//             return 0;
//         }
//         if (left <= start && right >= end) {
//             return tree[node];
//         }
//         int mid = (start + end) / 2;
//         int leftSum = query(2 * node + 1, start, mid, left, right);
//         int rightSum = query(2 * node + 2, mid + 1, end, left, right);
//         return leftSum + rightSum;
//     }

// public:
//     SegmentTree(const std::vector<int>& nums) {
//         n = nums.size();
//         tree.resize(4 * n);
//         build(nums, 0, 0, n - 1);
//     }

//     int query(int left, int right) {
//         return query(0, 0, n - 1, left, right);
//     }
// };
