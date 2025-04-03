#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define pb push_back
void READFILE(){
	freopen("DIV3.inp","r",stdin);
	freopen("DIV3.out","w",stdout);
}
int main(){
	fast;READFILE();
	ll n;cin>>n;
	vector<ll> a;
	ll cnt0=0;
	ll cnt1=0;
	ll cnt2=0;
	for(ll i=0;i<n;i++){
		ll x;cin>>x;
		cnt0+=((x%3==0)?1:0);
		cnt1+=((x%3==1)?1:0);
		cnt2+=((x%3==2)?1:0);


	}
	ll res=0;
	res+=(cnt0*(cnt0-1)/2);
	res+=(cnt1*cnt2);
	cout<<res;
}