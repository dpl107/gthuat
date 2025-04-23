#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr)
void xuly(int x,vector<int> &a,int n){
    for(int i=0;i<n;i++){
        if(a[i]==x){
            a[i]=0;
        }
    }
}
const int maxn = 1e6;
int d[maxn];
int main(){
    fast;
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        d[a[i]]++;
    }
    for(int i=0;i<m;i++){
        int x;cin>>x;
        xuly(x,a,n);
    }
    int res = -1e6;
    for(auto x:a){
        if(d[x]>=1){
            res = max(res,x*d[x]);
            d[x]=0;
        }
    }
    cout<<res;
}