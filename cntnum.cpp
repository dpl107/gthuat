#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main() {

	freopen("CNTNUM.INP","r",stdin);
	freopen("CNTNUM.OUT","w",stdout);
	ll a; ll b; ll c; ll d;
	cin >> a >>b>>c>>d;
	//Dem so boi cua C
	ll bec=0;
	if (a%c==0) {
		bec = a/c;
	} else { bec =(a/c)+1; }

	ll endc; endc = b/c;
//	cout << bec << " " << endc << " ";
	ll demc = endc - bec + 1;
//	cout << demc << endl;

	//dem so boi cua D
	ll bed=0; 
	if (a%d==0) {
		bed = a/d;
	} else { bed =(a/d)+1; }
	ll endd = b/d;
	ll demd = endd - bed + 1;
	// for (ll i = bed; i<=endd; i++) {
	// 	if ((d*i)%c==0) demd--;
	// }
	ll bcnn = c/gcd(c,d) * d;
	ll chung = ((b/bcnn)-((a/bcnn)+1)+1);
//	cout << bed << " " << demd << " ";

	cout << (b-a+1) - (demc + demd - chung);
}