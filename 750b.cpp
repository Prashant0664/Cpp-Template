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
    cin>>n;
    ll a=0,b=0;
    for(int i=0;i<n;i++){
        ll x;
        string s;
        cin>>x>>s;
        if(s=="South"){
            b+=x;
        }else if(s=="North"){
            b-=x;
        }else if(s=="East"){
            if(b==0 || b==20000){
                cout<<"NO"<<endl;
                return;
            }
        }else if(s=="West"){
            if(b==0 || b==-20000){
                cout<<"NO"<<endl;
                return;
            }
        }
        if(b<0 || b>20000){
            cout<<"NO"<<endl;
            return;
        }
    }
    pn(((b==0)?"YES":"NO"));
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