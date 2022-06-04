#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<long long> vl;

#define F 						first
#define S 						second
#define PB 						push_back
#define MP 						make_pair
#define f(i,a,b) 				for(ll i=a; i<b; i++)
#define rep(i,n) 				f(i,0,n)
#define w(t)					ll t; cin>>t; while(t--)
#define N 						10

constexpr ll int_pow(ll b, ll e) {
    return (e == 0) ? 1 : b * int_pow(b, e - 1);
}

void doublade() {
	ios::sync_with_stdio(false); cin.tie(0); cout.precision(10);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

ll power(ll n) {
	ll p=0;
	while(n>0) {
		p += n%10;
		n /= 10;
	}
	return p;
}

int main()
{
	doublade();
	w(t) {
		ll n;
		cin>>n;
		ll a[n], b[n];
		ll a_p=0, b_p=0;
		rep(i, n) {
			cin>>a[i]>>b[i];
			a[i] = power(a[i]);
			b[i] = power(b[i]);
			if(a[i]>b[i]) a_p++;
			else if(a[i]<b[i]) b_p++;
			else {
				a_p++;
				b_p++;
			}
		}
		if(a_p==b_p) cout<<"2 "<<b_p<<"\n";
		else if(a_p<b_p) cout<<"1 "<<b_p<<"\n";
		else cout<<"0 "<<a_p<<"\n";
	}
	return 0;
}