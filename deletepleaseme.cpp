// Given a binary integer N, the task is to convert it into base 6.
#include<bits/stdc++.h>
using namespace std;

int todecimal(string binary,int len){
	int decimal=0;
	int power=1;
	for(int i=len-1;i>=0;i--){
		if(binary[i]=='0'){
			decimal+=power*0;
			power<<=1;
		}
		else{
			decimal+=power*1;
			power<<=1;
		}
	}
	return decimal;
}

string tobase6(string s,int k){
	int n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			if(i+k<=n){
				for(int j=i;j<i+k;j++){
					if(s[j]=='0'){
						s[j]='1';
					}
					else{
						s[j]='0';
					}
				}
			}
		}
	}
	return s;
}

int main(){
	int ans=0;
	int maxi=0;
	// string bin="0";
	string s="101100";
	int a,b;
	cin>>a>>b;

	sort(s.begin()+a-1,s.begin()+(b-a+1));
	cout<<s<<endl;
	// for(int i=0;i<=bin.length();i++){
		
	// cout<<conv;
    return 0;
}