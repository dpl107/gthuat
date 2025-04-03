#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
# define ll long long
# define endl "\n"
# define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
const ll mod = 1ll*(1e9+7);
ll solve(vector<ll>& a) {
    ll dp0 = 1; 
    ll dp1 = 0; 
    ll dp2 = 0; 
    ll dp3 = 0; 
    ll i = 0;
    for (ll x : a) {
        ll n_dp0 = dp0;
        ll n_dp1 = dp1;
        ll n_dp2 = dp2;
        ll n_dp3 = dp3;
        
        if (x == 1) {
            n_dp1 += dp0;
        } else if (x == 2) {
            n_dp2 = dp1 + 2 * dp2;
        } else if (x == 3) {
            n_dp3 += dp2;
        }
        
        dp0 = n_dp0;
        dp1 = n_dp1;
        dp2 = n_dp2;
        dp3 = n_dp3;
        cout<<"arr ["<<i<<"] = "<<x<<"; dp0 = "<<dp0<<"; dp1 = "<<dp1<<"; dp2 = "<<dp2<<"; dp3 = "<<dp3<<"\n";
        i++;
    }
    
    return dp3;
}
int main(){
    fast;
    ll n;cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    cout<<solve(a)%mod;
}       
