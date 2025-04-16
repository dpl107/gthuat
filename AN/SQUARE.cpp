#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);
void READFILE(){
	freopen("SQUARE.inp","r",stdin);
	freopen("SQUARE.out","w",stdout);
}
int main(){
	fast;READFILE();
	ll n;cin>>n; 
	ll x_max=0,x_min=1e9,y_max=0,y_min=1e9;
	for(ll i=0;i<n;i++){
		ll x,y;cin>>x>>y;
		y_max = max(y,y_max);
		x_max = max(x,x_max);
		y_min = min(y,y_min);
		x_min = min(x,x_min);

	}
	ll c1 = x_max-x_min;
	ll c2 = y_max-y_min;
	cout<<max(c1,c2)*max(c1,c2);
}