#include<bits/stdc++.h>
using namespace std;
#define pn(x) cout<<x<<endl;
#define ps(x) cout<<x<<' ';
#define endo cout<<endl;
#define printv(v) for(auto x:v){ps(x);}endo;
#define printve(v) for(auto x:v){ps(x);};
typedef long long int ll;

void solution(){
    // ll n,m;
    // cin>>m;
    // cin>>n;
    // string s;
    // // cin>>s;
    // vector<ll>v(n);
    // for(int i=0;i<n;i++){
    //     cin>>v[i];
    // }
    // vector<ll>v1;
    // for(int i=0;i<m;i++){
    //     v1.push_back(i);
    // }
    // ll l=0;
    // for(int i=0;i<n;i++){
    //     l=(l+v[i])%m;

    //     cout<<v1[l]+1<<" - "<<l<<" ";
    //     vector<ll>v2;
    //     for(int j=0;j<v1.size();j++){
    //         if(j!=v1[l]){
    //             v2.push_back(v1[j]);
    //         }
    //     }
    //     endo;
    //     for(auto &i:v1){
    //         cout<<i<<" ";
    //     }
    //     // l++;
    //     endo;
    //     m--;
    //     v1=v2;
    //     // break;
    // }
 int n, k;
	cin >> n >> k;
	vector<int> vv;
	for (int i = 0; i < n; ++i)
		vv.push_back(i + 1);
	for (int i = 0; i < k; ++i) {
		int a;
		cin >> a;
		a %= vv.size();
		for (int j = 0; j < a; ++j)
			rotate(vv.begin(), vv.begin() + 1, vv.end());
		cout << vv[0] << " ";
		vv.erase(vv.begin());
	}
	cout << "\n";
    return;
}
int main(){
    int _=1;
    // cin>>_;
    while(_--){
        solution();
    }
    return 0;
}