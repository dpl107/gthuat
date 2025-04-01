#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
# define ll long long
# define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)

bool prime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
const ll maxn = (ll)1e7*1LL;
ll primes[(ll)1e7];
void sieve(){
    primes[0]=primes[1]=1;
    for(ll i=2;i*i<=maxn;i++){
        if(primes[i]==0){
            for(ll j=i*i;j<=maxn;j+=i)primes[j]=1;
        }
    }
}
int main() {
    fast;
    ll n;
    cin >> n;
    sieve();
    for(ll i=2;i<=n*n;i++){
        cout<<((primes[i]==0)?i:0)<<" ";
    }
}
