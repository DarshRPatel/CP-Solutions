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
#define MOD						(ll)1e9

void doublade() {
	ios::sync_with_stdio(false); cin.tie(0); cout.precision(10);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

// ll N = 200001;
vl adj[200001];
vector<bool> visited(200001, false);

ll dfs(ll s, ll &cnt) {
	visited[s] = true;
	cnt++;
	for(auto u:adj[s]) {
		if(!visited[u]) {
			dfs(u, cnt);
		}
	}
	return cnt;
}

int main() {
	doublade();
	// w(t) {
		ll n, m;
		cin >> n >> m;
		// vl a(n), b(m);
		rep(i, m) {
			ll x, y;
			cin >> x >> y;
			adj[x].PB(y);
			adj[y].PB(x);
		}
		ll ans = 0;
		rep(i, n) {
			if(!visited[i]) {
				ll cnt = 0;
				ans = max(ans, dfs(i, cnt));
			}
		}
		cout<<ans<<"\n";
	// }
	return 0;
}