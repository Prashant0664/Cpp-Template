// https://www.hackerearth.com/problem/algorithm/sallu-bhai-and-ias-8838ac8d/


#include <bits/stdc++.h>
#define pb push_back
#define PQ priority_queue<int>
#define ff first
#define all(v) v.begin(), v.end()
#define ss second
#define pii pair<int,int>
#define v1d vector<int>
#define vpi vector<pair<int,int>>
#define int long long
#define nl '\n'
#define rep(i,n) for((i)=0;(i)<(int)(n);(i)++) 
using namespace std;

template<typename T> void read(vector<T> &a){ for(T &e: a) cin>>e; } 
template<typename T> void print(vector<T> &a){ for(T &e: a) cout<<e<<" "; } 

void __print(int x) {cerr << x;}
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
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

void IOS(){ios::sync_with_stdio(false); cout.precision(10); cout << fixed;}

#define INF (1LL<<60)
int i, j, k;

#define LCM 2520
int bin(int a, int b){
	int res = 1;
	while(b){
		if(b&1)res = res*a%LCM;
		a = a*a%LCM;
		b >>=1;
	}
	return res;
}
v1d get(int x){
	v1d ans;
	while(x){
		ans.pb(x%10);
		x/=10;
	}
	return ans;
}
v1d a(10);
int dp[15][2530][520];
int f(int pos, int sum, int mask, bool tight, v1d dig){
	if(pos==-1){
		int x = 0, y= 0 ;
		for(int i=1; i<=9; i++){
			if(mask&(1<<(i-1))){
				x++;
				if(sum%i!=0)return 0;
			}
		}
		return 1;
	}
	if(!tight && dp[pos][sum][mask]!=-1){
		return dp[pos][sum][mask];
	}
	int d = tight ? dig[pos]:9;
	int newmask;
	int ans = 0;
	for(int i=0; i<=d; i++){
		newmask = mask;
		if(i)newmask = mask | 1<<(i-1);
		ans += f(pos-1, (sum+a[i])%LCM, newmask, tight & (dig[pos]==i), dig);
	}
	if(!tight)dp[pos][sum][mask] = ans;
	return ans;
}

void test_cases(){
	int l, r;
	cin>>l>>r;
	v1d dig = get(l-1);
	int a1 = f(dig.size()-1,0,0,1,dig);
	dig =  get(r);
	int a2 = f(dig.size()-1,0,0,1,dig);
	cout<<a2-a1<<nl;

}

int32_t main(){
	IOS();
	int nr=1;
      cin>>nr;
	a[0] = 0;
	for(int i=1; i<=9; i++)a[i] = bin(i,i);
	memset(dp, -1, sizeof dp);

      for(int i=1; i<=nr; i++){
            test_cases();
      }
	
	return 0;
}




