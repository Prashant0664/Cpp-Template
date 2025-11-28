#include<bits/stdc++.h>
using namespace std;
#define pn(x) cout<<x<<endl;
#define ps(x) cout<<x<<' ';
#define endo cout<<endl;
#define printv(v) for(auto x:v){ps(x);}endo;
#define printve(v) for(auto x:v){ps(x);};
#define mod 1000000007
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
int dp[20][2][20][20];
ll help(string &n,ll i,ll p,ll cnt, ll sum, ll&k){
    if(cnt>k){
        return 0;
    }
    if(i==n.size()){
        if(sum%k==0 && cnt==k){
            return 1;
        }
        return 0;
    }
    int limit;
    if(p==0){
        limit=9;
    }
    else{
        limit=n[i]-'0';
    }

    if(dp[i][p][cnt][sum]!=-1){
        return dp[i][p][cnt][sum];
    }
    
    ll ans=0;
    for(int ik=0;ik<=limit;ik++){
        int tp=p;
        int tcnt=cnt;
        if(ik<limit && p==1){
            tp=0;
        }
        if(n[ik]-'0'==k){
            tcnt++;
        }
        if(tcnt<=k){
            ans+=help(n,i+1,tp,tcnt,sum+ik,k);
        }
    }
    return dp[i][p][cnt][sum]=ans;
}

void solution(){
    ll n,m,k;
    cin>>n>>m>>k;
    string s=to_string(n);
    string t=to_string(m);
    memset(dp,-1,sizeof(dp));
    ll right=help(t,0,1,0,0,k);
    ll left=help(s,0,1,0,0,k);
    cout<<right<<" "<<left<<endl;
    cout<<right-left<<endl;
    return;
}
int main(){
    int _=1;
    cin>>_;
    int j=1;
    while(_--){
        // cout<<"Case "<<j++<<": ";
        solution();
    }
    return 0;
}