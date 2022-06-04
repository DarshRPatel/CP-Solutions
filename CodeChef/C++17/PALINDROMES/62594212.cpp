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

const ll N = 11;
vl fac(N);

void precompute() {
    fac[0] = fac[1] = 1;
    f(i, 2, N) fac[i] = i*fac[i-1];
}

// ll solve(vl &cnt) {
//     ll pairs = 0, odd = 0;
//     vl redundant;
//     rep(i, 26) {
//         odd += (cnt[i]%2);
//         ll tmp = (cnt[i]/2);
//         redundant.PB(tmp);
//         pairs += tmp;
//         if(odd>1) return 0;
//     }
//     ll res = fac[pairs];
//     for(auto x:redundant) res /= fac[x];

//     return res;
// }

void runcase() {
    ll n;
    string s;
    cin >> n >> s;
    vl cnt(26, 0);
    rep(i, n) {
        cnt[s[i]-'a']++;
    }

    ll pairs = 0, odd = 0;
    vl redundant;
    rep(i, 26) {
        odd += (cnt[i]%2);
        ll tmp = (cnt[i]/2);
        redundant.PB(tmp);
        pairs += tmp;
    }
    ll denom = 1;
    for(auto x:redundant) denom *= fac[x];
    ll s1 = (odd<=1) ? fac[pairs]/denom : 0;

    ll s2 = 0;
    rep(i, 26) {
        if(!cnt[i]) continue;

        odd -= (cnt[i]%2);
        pairs -= (cnt[i]/2);
        denom /= fac[(cnt[i]/2)];

        cnt[i]--;

        odd += (cnt[i]%2);
        pairs += (cnt[i]/2);
        denom *= fac[(cnt[i]/2)];
        
        rep(j, 26) {
            odd -= (cnt[j]%2);
            pairs -= (cnt[j]/2);
            denom /= fac[(cnt[j]/2)];

            cnt[j]++;

            odd += (cnt[j]%2);
            pairs += (cnt[j]/2);
            denom *= fac[(cnt[j]/2)];         

            if(odd<=1) amax(s2, fac[pairs]/denom);

            odd -= (cnt[j]%2);
            pairs -= (cnt[j]/2);
            denom /= fac[(cnt[j]/2)];

            cnt[j]--;

            odd += (cnt[j]%2);
            pairs += (cnt[j]/2);
            denom *= fac[(cnt[j]/2)];
        }
        odd -= (cnt[i]%2);
        pairs -= (cnt[i]/2);
        denom /= fac[(cnt[i]/2)];

        cnt[i]++;

        odd += (cnt[i]%2);
        pairs += (cnt[i]/2);
        denom *= fac[(cnt[i]/2)];
    }
    cout<<s1<<" "<<s2<<"\n";
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
        precompute();
        while(tests--) {
            runcase();
        }
    }
    return 0;
}