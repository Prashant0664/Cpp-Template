long long maxPoints(vector<vector<int>>& p) {
    vector<long long> cur_row(p[0].size()), prev_row(p[0].size());
    for (auto &row : p) {
        for (long long j = 0, run_max = 0; j < row.size(); ++j) {
            run_max = max(run_max - 1, prev_row[j]);
            cur_row[j] = run_max;
        }
        for (long long j = row.size() - 1, run_max = 0; j >= 0; --j) {
            run_max = max(run_max - 1, prev_row[j]);
            cur_row[j] = max(cur_row[j], run_max) + row[j];
        }
        swap(cur_row, prev_row);
    }
    return *max_element(begin(prev_row), end(prev_row));
}


/* ------------------------------------------------------------------------ */


class Solution {
public:
    long long maxPoints(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        vector<int>prev(m,0);
        vector<int>curr(m,0);
        for(int i=0;i<n;i++){
            int rm=0;
            for(int j=0;j<m;j++){
                rm=max(rm-1,prev[j]);
                curr[j]=rm;
            }
            rm=0;
            for(int j=m-1;j>=0;j--){
                rm=max(rm-1,prev[j]);
                curr[j]=max(curr[j],rm)+nums[i][j];
            }
            swap(curr,prev);
        }
        return *max_element(begin(prev), end(prev));
    }
};