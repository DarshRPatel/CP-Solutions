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

ll M, S, T, L, K, K_MAX;
vl x, n, p;
matrix t;

void read_input() {
    p.clear();

	cin >> M >> S >> T >> L;

	t.resize(M, vl(S));
    x.resize(S);
    n.resize(M);
	
    rep(i, M) {
		rep(j, S) {
            ll x;
            // cin >> x;
            cin >> t[i][j];
        }
	}
	rep(i, S) cin >> x[i];

    K_MAX = 0;
	rep(i, M) {
        cin >> n[i];
        K_MAX += n[i];
    }
}

void print_input() {
    cout<<M<<" "<<S<<" "<<T<<" "<<L<<"\n";
    rep(i, M) {
        rep(j, S) cout<<t[i][j]<<" ";
        cout<<"\n";
    }
    rep(i, S) cout<<x[i]<<" ";
    cout<<"\n";
    rep(i, M) cout<<n[i]<<" ";
    cout<<"\n";
}

void validate_output() {
    if(K>K_MAX) {
        cerr<<"K > K_MAX ERROR!\n";
        exit(0);
    }

    vl cnt(M, 0);
    rep(i, sz(p)) {
        ll x = p[i];
        if(x<0 || x>=M) {
            cerr<<"Invalid Car Type at pos: "<<(i+1)<<"\n";
            exit(0);
        }
        cnt[x]++;
    }

    rep(i, M) {
        if(cnt[i]>n[i]) {
            cerr<<"Cars of type: "<<(i+1)<<" produced is greater than required\n";
            exit(0);
        }
    }
}

void print_output() {
    validate_output();

    cout<<K<<"\n";
    for(auto x:p) cout<<(x+1)<<" ";
    cout<<"\n";
}

void naive_produce_everything_inorder() {
    K = 0;
    rep(i, M) K += n[i];
    rep(i, M) {
        rep(j, n[i]) p.PB(i);
    }
}


void runcase() {
	read_input();
    // print_input();

    naive_produce_everything_inorder();

    print_output();
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