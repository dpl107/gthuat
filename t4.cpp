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
bool prime(ll n){
    if(n<2)return false;
    if(n==2||n==3)return true;
    if(n%2==0||n%3==0)return false;
    for(ll i=5;i*i<=n;i+=6){
        if(n%i==0||n%(i+2)==0)return false;
    }
    return true;
}
int main(){
    fast;
    ll n=222;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0&&prime(i)){
            cout<<i<<" ";
            if(n/i!=i&&prime(n/i))cout<<n/i<<" ";
        }
    }
    if(n>1&&prime(n))cout<<n;
    cout<<n;
}    