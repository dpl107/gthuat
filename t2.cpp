#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
# define pb push_back
# define ins insert
# define ll long long
# define st string
# define endl "\n"
# define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
const ll maxn = 1e7;
ll a[maxn];
void xuli(ll n,ll k,ll a[]){
    ll res=0,tmp=0,start=0;
    for(ll i=0;i<k;i++)res+=a[i];
    res = tmp;
    for(ll i=k;i<n;i++){
        tmp = tmp + a[i] - a[i-k];
        if(tmp>=res){
            res = tmp;
            start = i-k+1;
        }
    }
    cout<<res<<"\n";
    for(ll i=start;i<start+k;i++){
        cout<<i<<" ";
    }
}
int main(){
    fast;
    ll n,k;cin>>n>>k;
    for(ll i=0;i<n;i++)cin>>a[i];
    xuli(n,k,a);
}    