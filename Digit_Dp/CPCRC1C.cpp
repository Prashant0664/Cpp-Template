// https://www.spoj.com/problems/CPCRC1C/

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

ll dp[11][2][100];

ll help(string &s, int i, int t, long long int cnt){
    if(i==s.length()){
        return cnt;
    }
    if(dp[i][t][cnt]!=-1){
        return dp[i][t][cnt];
    }
    int limit = (t==1?s[i]-'0':9);
    ll ans=0;
    for(int j=0;j<=limit;j++){
        ll ncnt=j+cnt;
        ans+=help(s,i+1,t&(j==limit),ncnt);
    }
    return dp[i][t][cnt]=ans;
}

void solution(){
    ll n,m;
    cin>>n;
    cin>>m;
    if(n==-1 && m==-1)return;
    n--;
    string a=to_string(n);
    memset(dp,-1,sizeof(dp));
    ll l=help(a,0,1,0);
    string b=to_string(m);
    memset(dp,-1,sizeof(dp));
    ll r=help(b,0,1,0);
    cout<<r-l<<endl;
    solution();
}
int main(){
    int _=1;
    // cin>>_;
    solution();
    return 0;
}