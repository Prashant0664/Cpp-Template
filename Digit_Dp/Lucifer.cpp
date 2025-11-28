// https://www.spoj.com/problems/LUCIFER/

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

int dp[20][2][91][91][2];
vector<int>primes={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
bool check(int sum){
    for(auto &i:primes){
        if(i==sum)return 1;
    }
    return 0;
}
int help(string s, int i, int p, int odd_sum, int even_sum, int e){
    if(i>=s.length()){
        return (check(even_sum-odd_sum)?1:0);
    }
    if(dp[i][p][odd_sum][even_sum][e]!=-1)return dp[i][p][odd_sum][even_sum][e];
    int limit=(p==1?s[i]-'0':9);
    int es=even_sum,os=odd_sum;
    int ans=0;
    for(int j=0;j<=limit;j++){
        if(e){
            es=even_sum+j;
        }
        else{
            os=odd_sum+j;
        }
        ans+=help(s,i+1,(p&(j==s[i]-'0')),os,es,!e);
    }
    return dp[i][p][odd_sum][even_sum][e]=ans;
}
void solution(){
    ll n;
    cin>>n;
    n--;
    string s=to_string(n);
    memset(dp,-1,sizeof(dp));
    int e=0;
    if(s.length()%2==0)e=1;
    int l=help(s,0,1,0,0,e);
    if(n==0)l=0;
    memset(dp,-1,sizeof(dp));
    cin>>n;
    s=to_string(n);
    e=0;
    if(s.length()%2==0)e=1;
    int r=help(s,0,1,0,0,e);
    pn(r-l);
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