#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<long long> vl;

#define F 						first
#define PB 						push_back
#define MP 						make_pair
#define f(i,a,b) 				for(ll i=a; i<b; i++)
#define rep(i,n) 				f(i,0,n)
#define w(t)					ll t; cin>>t; while(t--)
#define epsilon					1e-9

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

int main()
{
	doublade();
	// w(t) {
		ll x, y;
		cin>>x>>y;
		ll c = (4*x-y)/2;
		ll t = (y-2*x)/2;
		if(((4*x-y)%2==0 && (y-2*x)%2==0) && ((4*x-y)>=0 && (y-2*x)>=0)) {
			cout<<"Yes\n";
		}else cout<<"No\n";
	// }
	return 0;
}