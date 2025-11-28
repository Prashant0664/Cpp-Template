// // https://www.codechef.com/problems/DGTCNT?tab=statement

// #include<bits/stdc++.h>
// using namespace std;
// #define pn(x) cout<<x<<endl;
// #define ps(x) cout<<x<<' ';
// #define endo cout<<endl;
// #define printv(v) for(auto x:v){ps(x);}endo;
// #define printve(v) for(auto x:v){ps(x);};
// #define mod 1000000007
// #define pll pair<ll,ll>
// typedef long long int ll;

// void __print(int x) {cerr << x;}
// void __print(long x) {cerr << x;}
// void __print(long long x) {cerr << x;}
// void __print(unsigned x) {cerr << x;}
// void __print(unsigned long x) {cerr << x;}
// void __print(unsigned long long x) {cerr << x;}
// void __print(float x) {cerr << x;}
// void __print(double x) {cerr << x;}
// void __print(long double x) {cerr << x;}
// void __print(char x) {cerr << '\'' << x << '\'';}
// void __print(const char *x) {cerr << '\"' << x << '\"';}
// void __print(const string &x) {cerr << '\"' << x << '\"';}
// void __print(bool x) {cerr << (x ? "true" : "false");}

// template<typename T, typename V>
// void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
// template<typename T>
// void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
// void _print() {cerr << "]\n";}
// template <typename T, typename... V>
// void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
// #ifndef ONLINE_JUDGE
// #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
// #else
// #define debug(x...)
// #endif

// int dp[20][2][11];
// vector<ll>v(10,0);
// int help(string &s, int i, int p, int ele, int f){
//     if(i==s.length()){
//         if(f==v[ele]){
//             return 1;
//         }
//         return 0;
//     }
//     if(dp[i][p][f]!=-1){
//         return dp[i][p][f];
//     }
//     int limit=(p?s[i]-'0':9);
//     int ans=0;
//     for(int j=0;j<=limit;j++){
//         if(j==ele){
//             ans+=help(s,i+1,(p && ((limit==j)?1:0)),ele,f+1);
//         }
//         else{
//             ans+=help(s,i+1,(p && ((limit==j)?1:0)),ele,f);
//         }
//     }
//     return dp[i][p][f]=ans;
// }



// void solution(){
//     ll n,m;
//     cin>>n;
//     cin>>m;
//     for(int i=0;i<10;i++){
//         cin>>v[i];
//     }
//     ll c=0;
//     // debug(v);
//     string s=to_string(n-1);
//     string t=to_string(m);
//     for(int i=0;i<=9;i++){
        
//         memset(dp,-1,sizeof(dp));
//         int l=help(s,0,1,i,0);
//         memset(dp,-1,sizeof(dp));
//         int r=help(t,0,1,i,0);
//         // debug(make_pair(l,r));
//         c+=(r-l);
//         // debug(r);
//         // debug(make_pair(i,r));
//     }
//     pn(c);
//     cout<<m-n+1-c;
//     endo;
//     return;
// }
// int main(){
//     int _=1;
//     cin>>_;
//     while(_--){
//         solution();
//     }
//     return 0;
// }
// DGTCNT - standard solution

#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define PER(i,a,b) for(int i=(a);i>=(b);i--)
#define RVC(i,S) for(int i=0;i<(S).size();i++)
#define RAL(i,u) for(int i=fr[u];i!=-1;i=e[i].next)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
     
template<class T> inline
void read(T& num) {
    bool start=false,neg=false;
    char c;
    num=0;
    while((c=getchar())!=EOF) {
        if(c=='-') start=neg=true;
        else if(c>='0' && c<='9') {
            start=true;
            num=num*10+c-'0';
        } else if(start) break;
    }
    if(neg) num=-num;
}
/*============ Header Template ============*/

LL C[20][20]; // C(i,j)
LL pw[20][20]; // i ^ j
int a[20],b[20]; 
int spc[20];
int stk[20];
int cnt,top;

// calculate the answer for first c digits, while others are determined.

LL mul(int c) {
    LL res=1;
    REP(i,1,cnt) {
        if(b[spc[i]]<0) return 0;
        res*=C[c][b[spc[i]]];
        c-=b[spc[i]];
        if(c<0) return 0;
    }
    res*=pw[10-cnt][c];
    return res;
}

// calculate the answer for range [1, x]

LL count(LL x) {
    if(x==0) return 0;
    LL res=0;
    for(top=0;x;x/=10) stk[++top]=x%10;
    REP(i,0,9) b[i]=a[i];
    REP(i,1,top-1) REP(j,1,9) {
        b[j]--;res+=mul(i-1);b[j]++;
    }
    PER(i,top,1) {
        int st=0;
        if(i==top) st=1;
        REP(j,st,stk[i]-1) {
            b[j]--;res+=mul(i-1);b[j]++;
        }
        b[stk[i]]--;
    }
    res+=mul(0);
    return res;
}

void solve() {
    LL l,r,res=0;
    read(l);read(r);
    REP(i,0,9) read(a[i]);
    // the principle of inclusion-exclusion
    for(int i=0;i<(1<<10);i++) { 
        cnt=0;
        REP(k,0,9) if(i&(1<<k)) spc[++cnt]=k;
        if(cnt&1) res-=count(r)-count(l-1);
        else res+=count(r)-count(l-1);
    }
    printf("%lld\n",res);
}

void init() {
    pw[0][0]=1;
    REP(i,1,10) {
        pw[i][0]=1;
        REP(j,1,18) pw[i][j]=pw[i][j-1]*i;
    }
    REP(i,0,18) C[i][0]=1;
    REP(i,1,18) REP(j,1,i) C[i][j]=C[i-1][j-1]+C[i-1][j]; 
}

int main() {
    init();
    int T;
    read(T);
    while(T--) solve();
    return 0;
}