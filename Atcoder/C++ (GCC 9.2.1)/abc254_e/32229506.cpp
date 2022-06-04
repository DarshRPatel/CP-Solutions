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

bool checkSq(ll n) {
    ll tmp = sqrt(n);
    if((tmp*tmp)==n) return 1;
    tmp++;
    if((tmp*tmp)==n) return 1;
    return 0;
}

void runcase() {
    ll n;
    cin >> n;
    vl dp(n+1, 0), sq(n+1, 0);
    dp[1] = sq[1] = 1;
    f(i, 2, n+1) {
        bool isSq = checkSq(i);

        dp[i] = dp[i-1];
        if(isSq) {
            dp[i] += (2*sq[i-1] + 1);
        }else {
            ll num = 1, x = i, cnt = 0;
            
            while(x%2==0) {
                x /= 2;
                cnt++;
            }
            if(cnt%2) num *= 2;

            for(ll j=3; j*j<=x; j+=2) {
                if(x%j) continue;

                cnt = 0;
                while(x%j==0) {
                    x /= j;
                    cnt++;
                }
                if(cnt%2) num *= j;
            }

            if(x!=1) num *= x;

            ll residue = i/num;
            dp[i] += (2*(sq[residue]-1) + 1);

            // cout<<i<<" "<<num<<" "<<residue<<"\n";
        }
        sq[i] = sq[i-1]+isSq;
    }
    // for(auto x:dp) cout<<x<<" ";
    // cout<<"\n";
    cout<<dp[n]<<"\n";
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