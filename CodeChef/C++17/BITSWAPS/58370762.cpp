/* 𝔸ЦէђӨr: 𝔻𝔬ᵘ๒𝓵𝓪🅳𝕖 */

#include<bits/stdc++.h>
using namespace std;
using namespace chrono;

#pragma GCC optimize("-O2")

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<ll> vl;
typedef pair<ll, ll> pl;
typedef vector<vector<ll>> matrix;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )
#define F                         first
#define S                         second
#define PB                        push_back
#define PPB                       pop_back
#define MP                        make_pair
#define all(c)                    c.begin(), c.end()
#define f(i,a,b)                  for(ll i=a; i<b; i++)
#define rep(i,n)                  f(i,0,n)
#define fd(i, b, a)               for(ll i=b; i>=a; i--)
#define repr(i,n)                 fd(i, n-1, 0)
#define tr(c,i)                   for(typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define present(c,x)              (c.find(x) != c.end())    //for set and map
#define cpresent(c,x)             (find(all(c),x) != c.end())    //for vectors
#define ps(num, places)           fixed<<setprecision(places)<<num //use as cout<<ps(x, y)<<"\n";
#define sz(x)                     (ll)(x).size()

void setIO() { 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
}

void usaco(string filename) {
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
}

void amax(ll &a, ll b) { a = max(a, b); }
void amin(ll &a, ll b) { a = min(a, b); }

const lld epsilon = 1e-9;
const ll MOD = 1e9+7;
const ll INF = 1e9;

bool comp(ll a, ll b) {
    return (a > b);
}

ll POW(ll a, ll b) {
    ll res = 1;
    while(b>0) {
        if(b&1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

ll binpow(ll a, ll b, ll p=MOD) {
    ll res = 1;
    a %= p;
    while(b>0) {
        if(b&1) (res *= a)%=p;
        (a *= a)%=p;
        b >>= 1;
        a %= p;
        res %= p;
    }
    return res;
}

const ll N = 3e5+1;
vl arr[N], vis(N, 0), pos;

void clear(ll n) {
    rep(i, n) {
        arr[i].clear();
        vis[i] = 0;
    }
}

void dfs(ll u) {
    vis[u] = 1;
    pos.PB(u);
    for(auto x:arr[u]) {
        if(!vis[x]) dfs(x);
    }
}

void runcase() {
    ll n;
    cin >> n;
    clear(n);
    vl a(n), b;
    rep(i, n) cin >> a[i];
    b = a;
    sort(all(b));
    map<pl, ll> connected;
    rep(i, 32) {
        ll tmp = 1<<i;
        vl elem;
        rep(j, n) if(a[j]&tmp) elem.PB(j);
        f(j, 1, sz(elem)) {
            ll u = elem[j-1], v = elem[j];
            if(connected[{u, v}]) continue;
            arr[u].PB(v);
            arr[v].PB(u);
            connected[{u, v}] = 1;
        }
    }
    rep(i, n) {
        if(!vis[i]) {
            pos.clear();
            dfs(i);
            vl vals(sz(pos));
            rep(j, sz(vals)) vals[j] = a[pos[j]];
            sort(all(pos));
            sort(all(vals));
            rep(j, sz(pos)) a[pos[j]] = vals[j];
        }
    }
    rep(i, n) {
        if(a[i]!=b[i]) {
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.precision(10);
    #ifndef ONLINE_JUDGE
        setIO();
        // usaco("");
    #endif
    time__("Main") {
        ll tests = 1;
        cin >> tests;
        while(tests--) {
            runcase();
        }
    }
    return 0;
}