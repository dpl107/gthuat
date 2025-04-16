#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#define ll long long
#define st string
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
const ll maxn = 1e7;
ll d[maxn];

void dq(ll n) {
    while (n) {
        d[n] = d[n + 1] + n;  
        n--;
    }
}

int main() {
    fast;
    ll n;
    cin >> n;
    dq(n);
    for (ll i = 1; i <= n; ++i) {
        cout << d[i] << " ";  
    }
}
