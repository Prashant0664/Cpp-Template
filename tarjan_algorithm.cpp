class Solution {
public:
    vector<vector<int>>ans;
    void dfs(vector<vector<int>>&nums, int i, vector<int>&in, vector<int>&low, vector<int>&vis, int &time, int par=-1){
        vis[i]=1;
        in[i]=low[i]=time;
        time++;
        for(auto &k:nums[i]){
            if(k==par)continue;
            if(vis[k]==0){
                dfs(nums,k,in,low,vis,time,i);
                low[i]=min(low[i],low[k]);
                if(low[k]>in[i]){
                    ans.push_back({k,i});
                }
            }
            else{
                low[i]=min(low[i],low[k]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& nums) {
        vector<vector<int>>adj(n);
        for(auto &i:nums){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>in(n,0), vis(n,0), low(n,0);
        int time=1;
        dfs(adj,0,in,low,vis,time);
        return ans;

    }
};