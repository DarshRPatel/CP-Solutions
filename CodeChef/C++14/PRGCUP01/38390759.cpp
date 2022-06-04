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
#define w(t)					ll t; cin>>t; while(t--)
#define ps(num, places)			fixed<<setprecision(places)<<num //use as cout<<ps(x, y)<<"\n";
#define sz(x) 					(ll)(x).size()
#define lb						lower_bound
#define ub						upper_bound
#define nl						"\n"

const ld epsilon = 1e-9;
const ll MOD = 1e9+7;

const ll N = 8;
bool vis[N][N];
ll dis[N][N];
vl dx{-1, 1, -2, 2, -2, 2, -1, 1}, dy{2, 2, 1, 1, -1, -1, -2, -2};

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

bool isValid(ll x, ll y) {
	if(x<0 || x>=N || y<0 || y>=N) return false;
	if(vis[x][y]) return false;
	return true;
}

void bfs(ll sx, ll sy) {
	queue<pl> q;
	q.push({sx, sy});
	vis[sx][sy] = 1;
	dis[sx][sy] = 0;
	while(!q.empty()) {
		ll x = q.front().F, y = q.front().S;
		q.pop();
		rep(i, sz(dx)) {
			ll nx = x + dx[i], ny = y + dy[i];
			if(isValid(nx, ny)) {
				vis[nx][ny] = 1;
				dis[nx][ny] = dis[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
}

void runcase() {
	rep(i, N) rep(j, N) {
		vis[i][j] = 0;
		dis[i][j] = 0;
	}
	string start, end;
	cin >> start >> end;
	ll sx = start[0]-'a', sy = start[1]-'0'-1;
	ll ex = end[0]-'a', ey = end[1]-'0'-1;
	bfs(sx, sy);
	cout<<dis[ex][ey]<<"\n";
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