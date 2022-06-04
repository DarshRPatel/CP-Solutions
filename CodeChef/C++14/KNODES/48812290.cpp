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

const ll N = 1e5+1, mxN = log2(N)+1;
ll timer = 0;
vl arr[N], st(N), en(N), dep(N);
matrix par(N, vl(mxN, -1));

void YES() {
    cout<<"Yes\n";
}

void NO() {
    cout<<"No\n";
}

void clear(ll n) {
    timer = 0;
    rep(i, n+1) {
        arr[i].clear();
        rep(j, mxN) par[i][j] = -1;
    }
}

void precompute(ll n) {
    f(j, 1, mxN) {
        f(i, 1, n+1) {
            ll tmp = par[i][j-1];
            if(tmp!=-1) par[i][j] = par[tmp][j-1];
        }
    }
}

ll getLCA(ll a, ll b) {
    if(dep[a]>dep[b]) swap(a, b);
    ll diff = dep[b]-dep[a];
    while(diff) {
        ll i = log2(diff);
        b = par[b][i];
        diff -= (1<<i);
    }
    if(a==b) return a;
    repr(i, mxN) {
        if(par[a][i]!=par[b][i]) {
            a = par[a][i], b = par[b][i];
        }
    }
    return par[a][0];
}

void dfs(ll u, ll p, ll d) {
    par[u][0] = p;
    dep[u] = d;
    st[u] = timer++;
    for(auto x:arr[u]) {
        if(x!=p) dfs(x, u, d+1);
    }
    en[u] = timer-1;
}

void runcase() {
    ll n;
    cin >> n;
    clear(n);
    rep(i, n-1) {
        ll a, b;
        cin >> a >> b;
        arr[a].PB(b);
        arr[b].PB(a);
    }
    dfs(1, -1, 0);
    precompute(n);
    ll q;
    cin >> q;
    while(q--) {
        ll k;
        cin >> k;
        vl a(k);
        ll small_d = 1e18, S, mx_d = 0, D;
        rep(i, k) {
            cin >> a[i];
            if(dep[a[i]]>mx_d) {
                mx_d = dep[a[i]];
                D = a[i];
            }
            if(dep[a[i]]<small_d) {
                small_d = dep[a[i]];
                S = a[i];
            }
        }
        ll flag = 1, rem_D, rem_mx_d = 0;
        rep(i, k) {
            if(st[a[i]]<=st[D] && en[a[i]]>=en[D]) continue;
            else {
                flag = 0;
                if(dep[a[i]]>rem_mx_d) {
                    rem_mx_d = dep[a[i]];
                    rem_D = a[i];
                }
            }
        }
        if(flag) {
            YES();
            continue;
        }
        ll print = 0;
        rep(i, k) {
            if(st[a[i]]<=st[D] && en[a[i]]>=en[D]) continue;
            else if( !(st[a[i]]<=st[rem_D] && en[a[i]]>=en[rem_D]) ) {
                NO();
                print = 1;
                break;
            }
        }
        if(!print) {
            ll lca = getLCA(D, rem_D);
            if(st[lca]<=st[S] && en[lca]>=en[S]) YES();
            else NO();
        }
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
        cin >> tests;
        while(tests--) {
            runcase();
        }
    }
    return 0;
}