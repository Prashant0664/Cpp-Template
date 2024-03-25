class NumStrMaxComparator {
public:
    bool operator() (string &a, string &b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return  a < b;
    }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        make_heap(nums.begin(), nums.end(), NumStrMaxComparator()); // heapify cost O(N)
        while (k-- > 1) {
            pop_heap(nums.begin(), nums.end(), NumStrMaxComparator());
            nums.pop_back();
        }
        return nums.front();
    }
};