// https://www.spoj.com/problems/NUMTSN/

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

ll dp[51][2][51][51][51];

ll help(string &s, int i, int t, int a, int b, int c){
    if(i==s.length()){
        if(a==b && b==c && c>0)return 1;
        return 0;
    }
    if(dp[i][t][a][b][c]!=-1){
        return dp[i][t][a][b][c];
    }
    int limit = (t==1?s[i]-'0':9);
    ll ans=0;
    for(int j=0;j<=limit;j++){
        if(j==3){
            ans+=help(s,i+1,t&(j==limit),a+1,b,c);
        }
        else if(j==6){
            ans+=help(s,i+1,t&(j==limit),a,b+1,c);

        }
        else if(j==9){
            ans+=help(s,i+1,t&(j==limit),a,b,c+1);

        }
        else{
            ans+=help(s,i+1,t&(j==limit),a,b,c);
        }
    }
    return dp[i][t][a][b][c]=ans;
}

void solution(){
    string s,t;
    cin>>s>>t;

    string a=s;
    memset(dp,-1,sizeof(dp));
    ll l=help(a,0,1,0,0,0);
    string b=t;
    memset(dp,-1,sizeof(dp));
    ll r=help(b,0,1,0,0,0);
    cout<<r-l<<endl;
    endo;
    // solution();
}
int main(){
    int _=1;
    cin>>_;
    while(_-- )
    solution();
    return 0;
}