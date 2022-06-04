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

const ll N = 3e5+5;
vl arr[N];
vector<pl> score(N);

bool comp(pair<ll, pl> a, pair<ll, pl> b) {
    if(a.S.F==b.S.F && a.S.S==b.S.S) return (a.F < b.F);
    else if(a.S.F==b.S.F) return (a.S.S > b.S.S);
    return (a.S.F > b.S.F);
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

void clear(ll n) {
    rep(i, n+1) {
        arr[i].clear();
        score[i] = {0, 0};
    }
}

void dfs(ll u, ll par, ll curr_val) {
    ll sum = curr_val, p = sum/MOD;
    sum -= p*MOD;
    vector<pair<ll, pl>> children;
    for(auto x:arr[u]) {
        if(x==par) continue;
        dfs(x, u, 1);
        children.PB({x, score[x]});
    }
    sort(all(children), comp);
    rep(i, sz(children)) {
        p += (i+1)*children[i].S.F;
        sum += (i+1)*children[i].S.S;
        ll tmp = sum/MOD;
        sum -= tmp*MOD;
        p += tmp;
    }
    score[u] = {p, sum};
}

void runcase() {
    ll n, x;
    cin >> n >> x;
    clear(n);
    rep(i, n-1) {
        ll u, v;
        cin >> u >> v;
        arr[u].PB(v);
        arr[v].PB(u);
    }
    dfs(1, -1, 1);
    // f(i, 1, n+1) cout<<score[i].F<<" "<<score[i].S<<"\n";
    ll ans = (x*score[1].S)%MOD;
    cout<<ans<<"\n";
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