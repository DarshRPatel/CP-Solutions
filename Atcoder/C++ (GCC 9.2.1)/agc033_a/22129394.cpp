#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<long long> vl;
typedef pair<long long, long long> pl;
typedef vector<vector<long long>> matrix;

#define F                         first
#define S                         second
#define PB                         push_back
#define MP                         make_pair
#define all(c)                     c.begin(), c.end()
#define f(i,a,b)                 for(ll i=a; i<b; i++)
#define rep(i,n)                 f(i,0,n)
#define fd(i, b, a)                for(ll i=b; i>=a; i--)
#define repr(i,n)                fd(i, n-1, 0)
#define tr(c,i)                 for(typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define present(c,x)             (c.find(x) != c.end())    //for set and map
#define cpresent(c,x)             (find(all(c),x) != c.end())    //for vectors
#define ps(num, places)            fixed<<setprecision(places)<<num //use as cout<<ps(x, y)<<"\n";
#define sz(x)                     (ll)(x).size()

const ld epsilon = 1e-9;
const ll MOD = 1e9+7;

const ll N = 1005;
ll n, m;
ll oper[N][N];
vl dx{-1, 0, 1, 0}, dy{0, -1, 0, 1};
char a[N][N];

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

ll bfs(const vector<pl> start) {
    queue<pl> q;
    rep(i, sz(start)) {
        oper[start[i].F][start[i].S] = 0;
        q.push(start[i]);
    }
    ll res = 0;
    while(!q.empty()) {
        pl v = q.front();
        q.pop();
        rep(i, sz(dx)) {
            ll x = v.F+dx[i], y = v.S+dy[i];
            if(x<0 || x>=n || y<0 || y>=m || a[x][y]=='#') continue;
            a[x][y] = '#';
            oper[x][y] = oper[v.F][v.S]+1;
            res = max(res, oper[v.F][v.S]+1);
            q.push({x, y});
        }
    }
    return res;
}

void runcase() {
    cin >> n >> m;
    vector<pl> start;
    rep(i, n) {
        rep(j, m) {
            cin >> a[i][j];
            if(a[i][j]=='#') start.PB({i, j});
        }
    }
    ll ans = bfs(start);
    // rep(i, n) {
    //     rep(j, m) cout<<oper[i][j]<<" ";
    //     cout<<"\n";
    // }
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