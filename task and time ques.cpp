// You are given an integer array jobs, where jobs[i] is the amount of time it takes to complete the ith job.

// There are k workers that you can assign jobs to. Each job should be assigned to exactly one worker. The working time of a worker is the sum of the time it takes to complete all jobs assigned to them. Your goal is to devise an optimal assignment such that the maximum working time of any worker is minimized.

// Return the minimum possible maximum working time of any assignment.

// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/submissions/1217326372/
// https://leetcode.com/problems/matchsticks-to-square/
// https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/solutions/1009817/one-branch-cutting-trick-to-solve-three-leetcode-questions/
// 

class Solution {
public:
    int help(vector<int>&nums,int i,int k,int curr,vector<int>&worker,int &ans){
        if(curr>=ans){
            return ans;
        }
        if(i==nums.size()){
            return ans=curr;
        }
        unordered_set<int>st;
        for(int j=0;j<k;j++){
            if(st.find(worker[j])!=st.end())continue;
            st.insert(worker[j]);
            worker[j]+=nums[i];
            help(nums,i+1,k,max(curr,worker[j]),worker,ans);
            worker[j]-=nums[i];
        }
        return ans;
    }
    int minimumTimeRequired(vector<int>& nums, int k) {
        if(k==nums.size())return *max_element(nums.begin(),nums.end());
        vector<int>v(k+1,0);
        int ans=0;
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<nums.size();i+=k){
            ans+=nums[i];
        }
        return help(nums,0,k,0,v,ans);
    }
};