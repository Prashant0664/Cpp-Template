#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

// Finding the kth smallest element
// in the set using * because
//  find_by_order returns an iterator
// *(o_set.find_by_order(k))

// Finding the number of elements
// strictly less than k
// s.order_of_key(k)

int main()
{
    ordered_set s;
    s.insert(1);
    s.insert(13);
    s.insert(12);
    auto t=*s.find_by_order(2);
    cout<<t<<" ";
    return 0;
}