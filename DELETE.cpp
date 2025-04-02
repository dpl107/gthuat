#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
bool dayvalid(ll lo,ll hi,vector<ll>&a){
	if(a[lo]!=1||a[hi]!=3)return true;
	for(ll i=lo+1;i<hi;i++){
		if(a[i]!=2)return false;
	}
	return true;
}
void READFILE(){
	freopen("DELETE.inp","r",stdin);
	freopen("DELETE.out","w",stdout);
}
int main(){
	fast;READFILE;
	ll n;cin>>n;
	vector<ll> a(n);
	ll cnt=1;
	for(ll i=0;i<n;i++)cin>>a[i];
	vector<ll> res;
	ll lo=0,hi=n-1;
	if(a[0]==1)res.pb(a[0]);
	while(lo<hi){

	}
}