#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
# define ll long long
# define st string
# define endl "\n"
# define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
void print(vector<ll>&a){
    for(auto x:a)cout<<x<<" ";
    cout<<"\n";
}
int main(){
    fast;
    clock_t st,ed;
    st = clock();
    
    ll n;cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++)cin>>a[i];

    ll index,newnum;
    for(ll i=0;i<n;i++){
        index=i;
        newnum=a[i];
        while(index>0&&a[index-1]>newnum){
            a[index]=a[index-1];
            index--;
        }
        a[index]=newnum;
        cout<<"Buoc "<<i+1<<": ";
        print(a);
    }
    ed = clock();
    ll tt = double(ed-st)/double(CLOCKS_PER_SEC);
}       