#include <bits/stdc++.h> 
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define ll long long
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
ll sol(ll l, ll r, ll x) {
    return r / x - (l - 1) / x;
}
void READFILE(){
    freopen("CNTNUM.INP","r",stdin);
    freopen("CNTNUM.OUT", "w", stdout);
    }
int main() {
    fast;
    ll a,b,c,d;cin>>a>>b>>c>>d;
    cout<<(b-a+1)-(sol(a,b,c)+sol(a,b,d)-sol(a,b,c/gcd(c,d)*d));
}
