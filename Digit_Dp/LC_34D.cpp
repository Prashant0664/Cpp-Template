https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/
class Solution {
public:
    int dp[34][2][2];
    int help(string &s, int i, int flag, int prev){
        if(i==s.length())return 1;
        int ans=0;
        int flag1=0;
        if(dp[i][flag][prev]!=-1)return dp[i][flag][prev];
        flag1=flag?(s[i]=='1'):1;
        for(int j=0;j<=flag1;j++){
            if(prev & j)continue;
            ans+=help(s,i+1,flag&(flag1==j),j);
        }
        return dp[i][flag][prev]=ans;
    }
    int findIntegers(int n) {
        string s="";
        while(n!=0){
            s+=(n%2+'0');
            n/=2;
        }
        memset(dp,-1,sizeof(dp));
        reverse(s.begin(),s.end());
        cout<<s<<" ";
        return help(s,0,1,0);
    }
};