/* πΈΠ¦Υ§ΡΣ¨r: π»π¬α΅ΰΉπ΅πͺπ³π */

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

ll ask(ll v) {
    cout<<"? "<<v<<endl;
    char c;
    cin >> c;
    return (c=='B');
}
 
void runcase() {
    ll n;
    cin >> n;
    vl a;
    a.PB(1);
    f(i, 1, n+1) a.PB(i);
    matrix qry(n+1);
    rep(i, sz(a)) {
        f(j, a[i], n+1) qry[j].PB(ask(j));
    }
    matrix adj(n+1, vl(n+1, 0));
    f(i, 2, n+1) {
        for(ll j=1; j<i; j++) {
            adj[i][j] = adj[j][i] = (qry[i][j-1] ^ qry[i][j+1]);
        }
    }
    cout<<"!\n";
    f(i, 1, n+1) {
        f(j, 1, n+1) cout<<adj[i][j];
        cout<<"\n";
    }
    cout<<endl;
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