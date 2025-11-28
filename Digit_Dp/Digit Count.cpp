// https://lightoj.com/problem/digit-count

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

int dp[11][12];
int help(int n, int i, int prev, vector<int>&st){
    if(i==n){
        return 1;
    }
    if(dp[i][prev]!=-1)return dp[i][prev];
    int res=0;
    int uplimit=prev+2;
    int lower_limit=max(0,prev-2);
    for(int j=lower_limit;j<=uplimit;j++){
        if(st[j]==1){
            res+=help(n,i+1,j,st);
        }
    }
    return dp[i][prev]=res;
}
void solution(){
    ll n,m;
    cin>>n;
    cin>>m;
    vector<int>st(12,0);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        st[x]=1;
    }
    memset(dp,-1,sizeof(dp));
    ll ans=0;
    for(int i=0;i<st.size();i++){
        if(st[i]==1){
            ans+=help(m,1,i,st);
        }
    }
    cout<<ans<<endl;
    return;
}
int main(){
    int _=1;
    cin>>_;
    int i=0;
    while(_--){
        i++;
        cout<<"Case "<<i<<": ";
        solution();
    }
    return 0;
}