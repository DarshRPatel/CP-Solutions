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
const ll MOD = 998244353;
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

// (suff[0]-0)+(suff[1]-0)+(suff[2]-0) = suff(0-2) - 3*0 = 4 - 3*0 = 4

// (suff[0]-suff[2])+(suff[1]-suff[2]) = suff(0-1) - 2*suff[2] = 3 - 2*1 = 1

// (suff[0]-suff[1]) = sudd(0) - 1*suff[1] = 2 - 1*1 = 1

void runcase() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vl suff(n, 0);
    repr(i, n) {
        suff[i] = (s[i]=='1');
        if(i<(n-1)) suff[i] += suff[i+1];
    }
    vl prefSuff(n, 0);
    prefSuff[0] = suff[0];
    f(i, 1, n) prefSuff[i] = suff[i]+prefSuff[i-1];
    vl arr(n, 0);
    rep(i, n) {
        arr[i] = prefSuff[i];
        if(i<(n-1)) arr[i] -= (i+1)*suff[i+1];
        arr[i] %= 2;
    }
    ll res = 0, pow = 1;
    repr(i, n) {
        if(arr[i]) (res += pow)%=MOD;
        (pow *= 2)%=MOD;
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
        cin >> tests;
        while(tests--) {
            runcase();
        }
    }
    return 0;
}