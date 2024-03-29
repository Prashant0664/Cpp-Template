// https://leetcode.com/problems/describe-the-painting/


class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<vector<long long>>ans;
        vector<long long>v(100000+5,0);
        vector<bool>e(100000+5,0);
        for(auto &i:segments){
            v[i[0]]+=i[2];
            v[i[1]]-=i[2];
            e[i[1]]=1;
            e[i[0]]=1;
        }
        long long sum=0;
        int prev=0;
        for(int i=1;i<100005;i++){
            if(e[i]==1 && sum>0){
                ans.push_back({prev,i,sum});
            }
            if(e[i])prev=i;
            sum+=v[i];
        }
        return ans;
    }
};