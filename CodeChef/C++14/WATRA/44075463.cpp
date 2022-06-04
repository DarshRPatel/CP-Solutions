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

const ll N = 405;
ll n, m, k, currFlow;
bool flag = 0;
char dir[N][N];
matrix a(N, vl(N)), vis(N, vl(N));

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

bool isValid(ll x, ll y, ll k) {
    if(x<1 || x>n || y<1 || y>m || vis[x][y] || k<currFlow) return 0;
    return 1;
}

void solve() {
    priority_queue<pair<ll, pl>> pq;
    pq.push({k, {1, 1}});
    f(i, 1, n+1) {
        f(j, 1, m+1) vis[i][j] = 0;
    }
    while(!pq.empty()) {
        ll rem = pq.top().F, x = pq.top().S.F, y = pq.top().S.S;
        pq.pop();
        if(rem<0 || vis[x][y]) continue;
        vis[x][y] = 1;
        if(x==n && y==m) {
            flag = 1;
            break;
        }
        if(dir[x][y]=='U') {
            if(isValid(x-1, y, a[x][y])) pq.push({rem, {x-1, y}});
            if(isValid(x, y+1, a[x][y]-1)) pq.push({rem-1, {x, y+1}});
            if(isValid(x+1, y, a[x][y]-2)) pq.push({rem-2, {x+1, y}});
            if(isValid(x, y-1, a[x][y]-3)) pq.push({rem-3, {x, y-1}});
        }else if(dir[x][y]=='R') {
            if(isValid(x, y+1, a[x][y])) pq.push({rem, {x, y+1}});
            if(isValid(x+1, y, a[x][y]-1)) pq.push({rem-1, {x+1, y}});
            if(isValid(x, y-1, a[x][y]-2)) pq.push({rem-2, {x, y-1}});
            if(isValid(x-1, y, a[x][y]-3)) pq.push({rem-3, {x-1, y}});
        }else if(dir[x][y]=='D') {
            if(isValid(x+1, y, a[x][y])) pq.push({rem, {x+1, y}});
            if(isValid(x, y-1, a[x][y]-1)) pq.push({rem-1, {x, y-1}});
            if(isValid(x-1, y, a[x][y]-2)) pq.push({rem-2, {x-1, y}});
            if(isValid(x, y+1, a[x][y]-3)) pq.push({rem-3, {x, y+1}});
        }else {
            if(isValid(x, y-1, a[x][y])) pq.push({rem, {x, y-1}});
            if(isValid(x-1, y, a[x][y]-1)) pq.push({rem-1, {x-1, y}});
            if(isValid(x, y+1, a[x][y]-2)) pq.push({rem-2, {x, y+1}});
            if(isValid(x+1, y, a[x][y]-3)) pq.push({rem-3, {x+1, y}});
        }
    }
}

void runcase() {
    cin >> n >> m >> k;
    f(i, 1, n+1) {
        f(j, 1, m+1) cin >> a[i][j];
    }
    f(i, 1, n+1) {
        f(j, 1, m+1) cin >> dir[i][j];
    }
    ll l = 0, r = 1e9, ans = l;
    while(l<=r) {
        ll mid = l + (r-l)/2;
        currFlow = mid;
        flag = 0;
        solve();
        if(flag) {
            ans = mid;
            l = mid+1;
        }else r = mid-1;
    }
    cout<<ans<<"\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.precision(10);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ll tests = 1;
    cin >> tests;
    while(tests--) {
        runcase();
    }
    return 0;
}