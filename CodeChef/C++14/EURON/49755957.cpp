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

struct segtree {
    ll size;
    vl seg;
    const ll ID = 0;
    void init(ll n) {
        size = 1;
        while(size<n) size *= 2;
        seg.assign(2*size, ID);
    }
    void add(ll i, ll v) {
        i += size;
        seg[i] += v;
        for(i/=2; i; i/=2) seg[i] = seg[2*i]+seg[2*i+1];
    }
    ll qry(ll l, ll r) {
        ll res = 0;
        for(l+=size, r+=size; l<=r; l/=2, r/=2) {
            if(l%2==1) res += seg[l++];
            if(r%2==0) res += seg[r--];
        }
        return res;
    }
};

void runcase() {
    ll n;
    cin >> n;
    vl a(n), cmp;
    rep(i, n) cin >> a[i];
    cmp = a;
    sort(all(cmp));
    cmp.erase(unique(all(cmp)), cmp.end());
    auto cid = [&](ll x) { return lower_bound(all(cmp), x)-cmp.begin(); };

    segtree st;
    st.init(n);

    ll res = 0;
    rep(i, n) {
        res += st.qry(cid(a[i])+1, sz(cmp)-1);
        st.add(cid(a[i]), 1);
    }
    cout<<res<<"\n";
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