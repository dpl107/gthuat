#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
void READFILE(){
	freopen("DIV3.inp","r",stdin);
	freopen("DIV3.out","w",stdout);
}
int main(){
	fast;READFILE();
	ll n;cin>>n;
	vector<ll> a(n);
	ll cnt=0;
	for(ll i=0;i<n;i++)
		cin>>a[i];
	for(ll i=0;i<n-1;i++){
		for(ll j=i+1;j<n;j++){
			if((a[i]+a[j])%3==0)cnt++;
		}
	}
	cout<<cnt;
}