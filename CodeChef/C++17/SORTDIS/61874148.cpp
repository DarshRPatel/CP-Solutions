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
const ll INF = 1e18;

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

const pl phi = {-1, -1};

bool areEqual(const pl &a, const pl &b) {
    return (a.F==b.F && a.S==b.S);
}

// bool isIn(const pl &a, const pl &b) {
//     // if a is in b
//     return (b.F<=a.F && a.S<=b.F);
// }

pl getRange(const ll &a, const ll &b) {
    if(a<0 || b<0) cerr<<"Error\n";

    ll tmp = a+b;
    if(a<b) return {0, tmp/2};
    else if(a==b) return {0, INF};
    else return {ceil((double)tmp/2.0), INF};
}

pl getIntersection(const pl &a, const pl &b) {
    if(areEqual(a, phi) || areEqual(b, phi)) return phi;

    pl tmp = {max(a.F, b.F), min(a.S, b.S)};
    if(tmp.F>tmp.S) return phi;
    return tmp;
}

struct segtree {
    ll size;
    vector<pl> tree;
    const pl ID = {1, INF};
    void init(ll n) {
        size = 1;
        while(size<n) size *= 2;
        tree.assign(2*size, ID);
    }
    void build(const vector<pl> &b) {
        rep(i, sz(b)) tree[i+size] = b[i];
        fd(i, size-1, 1) tree[i] = getIntersection(tree[2*i], tree[2*i+1]);
    }
    void upd(ll i, pl v) {
        tree[i+=size] = v;
        for(i/=2; i; i/=2) tree[i] = getIntersection(tree[2*i], tree[2*i+1]);
    }
    ll qry(ll l, ll r) {
        pl res = {0, INF};
        for(l+=size, r+=size; l<=r; l/=2, r/=2) {
            if(l%2==1) res = getIntersection(res, tree[l++]);
            if(r%2==0) res = getIntersection(res, tree[r--]);
            if(areEqual(res, phi)) return -1;
        }
        return res.F;
    }
    void display() {
        f(i, 1, sz(tree)) {
            cout<<tree[i].F<<" "<<tree[i].S<<"\n";
        }
    }
};

void runcase() {
    ll n, q;
    cin >> n >> q;
    vl a(n);
    rep(i, n) cin >> a[i];

    if(n==1) {
        while(q--) {
            ll type, x, y;
            cin >> type >> x >> y;
            if(type==2) cout<<"0\n";
        }
        return;
    }

    vector<pl> b(n-1);
    rep(i, n-1) {
        b[i] = getRange(a[i], a[i+1]);
        // cout<<b[i].F<<" "<<b[i].S<<"\n";
    }

    segtree st;
    st.init(n);
    st.build(b);

    while(q--) {
        ll type;
        cin >> type;
        if(type==1) {
            ll pos, val;
            cin >> pos >> val;
            pos--;

            // updates
            a[pos] = val;
            if(pos) {
                b[pos-1] = getRange(a[pos-1], a[pos]);
                st.upd(pos-1, b[pos-1]);
            }
            if((pos+1)<n) {
                b[pos] = getRange(a[pos], a[pos+1]);
                st.upd(pos, b[pos]);
            }

        }else {
            ll l, r;
            cin >> l >> r;
            l--, r--;

            if(l==r) cout<<"0\n";
            else cout<<st.qry(l, r-1)<<"\n";
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
        // cin >> tests;
        while(tests--) {
            runcase();
        }
    }
    return 0;
}