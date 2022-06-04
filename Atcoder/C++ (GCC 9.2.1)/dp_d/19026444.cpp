#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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
#define fd(i, b, a)				for(ll i=b; i>=a; i--)
#define repr(i,n)				fd(i, n-1, 0)
#define tr(c,i) 				for(typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define present(c,x) 			(c.find(x) != c.end())	//for set and map
#define cpresent(c,x) 			(find(all(c),x) != c.end())	//for vectors
#define ps(num, places)			fixed<<setprecision(places)<<num //use as cout<<ps(x, y)<<"\n";
#define sz(x) 					(ll)(x).size()

const ld epsilon = 1e-9;
const ll MOD = 1e9+7;

bool comp(ll a, ll b) {
	return (a > b);
}

ll binpow(ll a, ll b) {
	ll res = 1;
	while(b>0) {
		if(b&1) res *= a;
		a = a*a;
		b >>= 1;
	}
	return res;
}

void runcase() {
	ll n;
	cin >> n;
	vl a(n), b(n), c(n);
	rep(i, n) {
		cin >> a[i] >> b[i] >> c[i];
	}
	matrix hp(n, vl(3, 0));
	hp[0][0] = a[0], hp[0][1] = b[0], hp[0][2] = c[0];
	f(i, 1, n) {
		hp[i][0] = max(hp[i][0], a[i]+hp[i-1][1]);
		hp[i][0] = max(hp[i][0], a[i]+hp[i-1][2]);

		hp[i][1] = max(hp[i][1], b[i]+hp[i-1][0]);
		hp[i][1] = max(hp[i][1], b[i]+hp[i-1][2]);

		hp[i][2] = max(hp[i][2], c[i]+hp[i-1][0]);
		hp[i][2] = max(hp[i][2], c[i]+hp[i-1][1]);
	}
	// rep(i, n) {
	// 	rep(j, 3) cout<<hp[i][j]<<" ";
	// 	cout<<"\n";
	// }
	ll ans = max(hp[n-1][0], max(hp[n-1][1], hp[n-1][2]));
	cout<<ans<<"\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.precision(10);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ll tests = 1;
	// cin >> tests;
	while(tests--) {
		runcase();
	}
	return 0;
}