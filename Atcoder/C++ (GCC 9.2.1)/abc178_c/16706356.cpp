#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<long long> vl;
typedef pair<long long, long long> pl;
typedef vector<vector<long long>> matrix;

#define F 						first
#define S 						second
#define PB 						push_back
#define MP 						make_pair
#define all(c) 					c.begin(), c.end()
#define f(i,a,b) 				for(ll i=a; i<b; i++)
#define rep(i,n) 				f(i,0,n)
#define tr(c,i) 				for(typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define present(c,x) 			(c.find(x) != c.end())	//for set and map
#define cpresent(c,x) 			(find(all(c),x) != c.end())	//for vectors
#define w(t)					ll t; cin>>t; while(t--)
#define epsilon 				1e-9
// #define MOD						(ll)(1e9+7)

void doublade() {
	ios::sync_with_stdio(false); cin.tie(0); cout.precision(10);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

const ll MOD = 1e9+7;

ll  binpow(ll a, ll b) {
	ll res = 1;
	while(b>0) {
		if(b&1) res *= a%MOD;
		a = (a*a)%MOD;
		b >>= 1;
		res %= MOD;
		a %= MOD;
	}
	return res;
}

int main() {
	doublade();
	// w(t) {
		ll n;
		cin >> n;
		if(n==1) cout<<"0\n";
		else {
			ll ans = 0;
			ans = (binpow(10, n)%MOD-2*binpow(9, n)%MOD+binpow(8, n)%MOD)%MOD;
			if(ans<0) {
				ans += MOD;
			}
			cout<<ans<<"\n";
		}
	// }
	return 0;
}