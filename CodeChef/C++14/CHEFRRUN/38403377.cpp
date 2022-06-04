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
// #define tr(c,i) 				for(typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define present(c,x) 			(c.find(x) != c.end())	//for set and map
#define cpresent(c,x) 			(find(all(c),x) != c.end())	//for vectors
#define w(t)					ll t; cin>>t; while(t--)
#define ps(num, places)			fixed<<setprecision(places)<<num //use as cout<<ps(x, y)<<"\n";
#define sz(x) 					(ll)(x).size()
#define lb						lower_bound
#define ub						upper_bound
#define nl						"\n"

const ld epsilon = 1e-9;
const ll MOD = 1e9+7;

const ll N = 1e5;
ll ans = 0;
vl ar[N], tr[N], vis(N, 0), order, SCC;

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

void dfs(ll u) {
	vis[u] = 1;
	for(auto x:ar[u]) {
		if(!vis[x]) dfs(x);
	}
	order.PB(u);
}

void dfs1(ll u) {
	vis[u] = 1;
	for(auto x:tr[u]) {
		if(!vis[x]) dfs1(x);
	}
	SCC.PB(u);
}

void runcase() {
	ll n;
	cin >> n;
	
	rep(i, n) {
		ar[i].clear();
		tr[i].clear();
		vis[i] = 0;
	}
	order.clear();
	SCC.clear();
	ans = 0;

	rep(i, n) {
		ll tmp;
		cin >> tmp;
		tmp += i+1;
		tmp %= n;
		ar[i].PB(tmp);
		tr[tmp].PB(i);
	}
	rep(i, n) {
		if(!vis[i]) dfs(i);
	}
	rep(i, n) vis[i] = 0;

	repr(i, n) {
		if(!vis[order[i]]) {
			SCC.clear();
			dfs1(order[i]);
			if(sz(SCC)==1 && ( SCC[0] != ar[SCC[0]][0] )) continue;
			ans += sz(SCC);
		}
	}

	cout<<ans<<"\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.precision(10);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ll tests;
	cin >> tests;
	while(tests--) {
		runcase();
	}
	return 0;
}