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
bool prm(ll n){
    if(n<=1)return 0;
    if(n==2||n==3)return 1;
    if(n%2==0||n%3==0)return 0;
    for(ll i=6;(i-1)*(i-1)<=n;i+=6){
        if(n%(i-1)==0||n%(i+1)==0)return 0;
    }
    return 1;
}
const maxn = 1e7*1LL;
ll d[maxn];
void sang(){
    d[0] = d[1] = 1;
    for(ll i=2;i*i<maxn;i++){
        if(d[i]==0)
        for(ll j=i*i;j<maxn;j+=i){
            d[j] =1;
        }
    }
}
void sanguocntomin(){
    for(ll i=2;i<maxn;i++){
        if(d[i]==0)for(ll j=i*2;j<maxn;j+=i){
            if(d[j]==0)d[j]=i;
        }
    }
}
ll gcd(ll a,ll b){
     
}
int main(){
    fast;
    
    
}    