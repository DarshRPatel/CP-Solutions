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

template <typename T> void amax(T &a, T b) { a = max(a, b); }
template <typename T> void amin(T &a, T b) { a = min(a, b); }

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

const ll N = 15e4+1;
vl arr[N], vis(N, 0);
ll sum[N][4];

void bfs(ll u, ll visMark) {
    queue<pl> q;
    q.push({u, 0});

    while(!q.empty()) {
        pl tmp = q.front();
        q.pop();

        ll v = tmp.F, dis = tmp.S;
        if(vis[v]==visMark) continue;
        vis[v] = visMark;
        sum[u][dis] += v;

        if(dis==3) continue;

        for(auto x:arr[v]) {
            if(vis[x]!=visMark) q.push({x, dis+1});
        }
    }
}

void runcase() {
    ll n, m;
    cin >> n >> m;

    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        arr[a].PB(b);
        arr[b].PB(a);
    }

    memset(sum, 0, sizeof(sum));

    f(i, 1, n+1) {
        bfs(i, i);
        // cout<<sum[i][0]<<" ";
        f(j, 1, 4) {
            // cout<<sum[i][j]<<" ";
            sum[i][j] += sum[i][j-1];
        }
        // cout<<"\n";
    }
    
    ll q;
    cin >> q;
    while(q--) {
        ll x, k;
        cin >> x >> k;
        cout<<sum[x][k]<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.precision(10);
    #ifndef ONLINE_JUDGE
        setIO();
        // usaco("");
    #endif
    time__("Main") {
        ll tests = 1;
        // cin >> tests;
        while(tests--) {
            runcase();
        }
    }
    return 0;
}