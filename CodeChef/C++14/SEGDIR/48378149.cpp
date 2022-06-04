#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<long long> vl;
typedef pair<long long, long long> pl;
typedef vector<vector<long long>> matrix;

#define F                         first
#define S                         second
#define PB                         push_back
#define MP                         make_pair
#define all(c)                     c.begin(), c.end()
#define f(i,a,b)                 for(ll i=a; i<b; i++)
#define rep(i,n)                 f(i,0,n)
#define fd(i, b, a)                for(ll i=b; i>=a; i--)
#define repr(i,n)                fd(i, n-1, 0)
#define tr(c,i)                 for(typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define present(c,x)             (c.find(x) != c.end())    //for set and map
#define cpresent(c,x)             (find(all(c),x) != c.end())    //for vectors
#define ps(num, places)            fixed<<setprecision(places)<<num //use as cout<<ps(x, y)<<"\n";
#define sz(x)                     (ll)(x).size()

const ld epsilon = 1e-9;
const ll MOD = 1e9+7;

bool comp(pair<pl, ll> a, pair<pl, ll> b) {
    return (a.S < b.S);
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while(b>0) {
        if(b&1) res *= a;
        a = a*a;
        b >>= 1;
    }
    return res;
}

ll overlap(pl a, pl b, pl c) {
    pl l = {max(a.F, b.F), min(a.S, b.S)};
    if(l.F>l.S) return 0;
    pl r = {max(b.F, c.F), min(b.S, c.S)};
    if(r.F>r.S) return 0;
    pl res = {max(l.F, r.F), min(l.S, r.S)};
    return max(0LL, res.S-res.F+1);
}

void runcase() {
    ll n;
    cin >> n;
    vector<pair<pl, ll>> a(n);
    rep(i, n) cin >> a[i].F.F >> a[i].F.S >> a[i].S;
    sort(all(a), comp);
    set<ll> elem;
    map<ll, vector<pl>> m;
    rep(i, n) {
        elem.insert(a[i].S);
        m[a[i].S].PB(a[i].F);
    }
    for(auto x:elem) {
        vector<pl> a = m[x];
        rep(i, sz(a)) {
            f(j, i+1, sz(a)) {
                f(k, j+1, sz(a)) {
                    if(overlap(a[i], a[j], a[k])) {
                        cout<<"NO\n";
                        return;
                    }
                }
            }
        }
    }
    cout<<"YES\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.precision(10);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ll tests = 1;
    cin >> tests;
    while(tests--) {
        runcase();
    }
    return 0;
}