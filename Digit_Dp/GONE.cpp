// https://www.spoj.com/problems/GONE/

#include<bits/stdc++.h>
using namespace std;
#define pn(x) cout<<x<<endl;
#define ps(x) cout<<x<<' ';
#define endo cout<<endl;
#define printv(v) for(auto x:v){ps(x);}endo;
#define printve(v) for(auto x:v){ps(x);};
#define mod 1000000007
#define pll pair<ll,ll>
typedef long long int ll;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif



int dp[10][2][80];
vector<int>prime={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
bool check(int sum){
    for(auto &i:prime)
        if(sum==i) return true;
    return 0;
}
int help(string &s, int i, int f, int sum){
    if(i==s.length()){
        if(check(sum)){
            return 1;
        }
        return 0;
    }
    if(dp[i][f][sum]!=-1){
        return dp[i][f][sum];
    }
    int ans=0;
    int limit=(f==1)?(s[i]-'0'):9;
    for(int j=0;j<=limit;j++){
        int nc=sum+j;
        int nf=(f==1 && j==limit)?1:0;
        ans+=help(s,i+1,nf,nc);
    }
    return dp[i][f][sum]=ans;
}


void solution(){
    ll n,m;
    cin>>m;
    cin>>n;
    // count number whose sum is prime from m to n
    string s=to_string(n);
    memset(dp,-1,sizeof(dp));
    int r=help(s,0,1,0);
    s=to_string(m-1);
    memset(dp,-1,sizeof(dp));
    int l=help(s,0,1,0);
    cout<<r-l<<endl;
    return;
}
int main(){
    int _=1;
    cin>>_;
    while(_--){
        solution();
    }
    return 0;
}