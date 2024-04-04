#include<bits/stdc++.h>
using namespace std;
#define pn(x) cout<<x<<endl;
#define ps(x) cout<<x<<' ';
#define endo cout<<endl;
#define printv(v) for(auto x:v){ps(x);}endo;
#define printve(v) for(auto x:v){ps(x);};
typedef long long int ll;

void solution(){
    ll n,m;
    ll k;
    cin>>n;
    ll f=n;
    cin>>k;
    vector<string>v;
    for(int i=1;i<=n;i++){
        string s=to_string(i);
        string t=s;
        reverse(s.begin(),s.end());
        t+=s;
        v.push_back(t);
    }
    // string s="00";vector<string>v;
    // v.push_back("");
    // k++;
    // n++;
    // while(1){
    //     vector<string>v2;
    //     int o=v.size();
    //     for(int j=0;j<o;j++){
    //         string g="0"+v[j]+"0";
    //         for(int l=0;l<=9;l++){
    //             g[0]=l+'0';
    //             g[g.length()-1]=l+'0';
    //             v.push_back(g);
    //         }
            
    //         n-=9;
    //         if(n<=0){
    //             goto hell;
    //         }
    //     }
    // }
    hell:
    ll ans=0;
    int i=1;
    // while(f){
    //     if(v[i][0]=='0'){i++;continue;}
    //     ll x=stoll(v[i]);
    //     ans=(ans+x)%k;
    //     f--;
    // }
    for(auto x:v){
        ll y=stoll(x);
        ans=(ans+y)%k;
    }
    pn(ans);
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