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

bool comp(ll a, ll b) {
    return (a > b);
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

void print(const matrix &a) {
    rep(i, sz(a)) {
        rep(j, sz(a[i])) cout<<a[i][j]<<" ";
        cout<<"\n";
    }
}

void runcase() {
    ll R, C, X;
    cin >> R >> C >> X;
    matrix a(R, vl(C)), b(R, vl(C));
    rep(i, R) {
        rep(j, C) cin >> a[i][j];
    }
    rep(i, R) {
        rep(j, C) cin >> b[i][j];
    }
    rep(j, C) {
        ll idx = 0;
        while(idx+X-1<R) {
            ll tmp = b[idx][j] - a[idx][j];
            for(ll i=idx; i<idx+X; i++) a[i][j] += tmp;
            idx++;
            // print(a);
        }
    }
    f(i, R-X+1, R) {
        ll idx = 0;
        while(idx+X-1<C) {
            ll tmp = b[i][idx] - a[i][idx];
            for(ll j=idx; j<idx+X; j++) a[i][j] += tmp;
            idx++;
            // print(a);
        }
    }
    bool flag = 1;
    rep(i, R) {
        rep(j, C) {
            if(a[i][j]!=b[i][j]) {
                flag = 0;
                break;
            }
        }
    }
    if(flag) cout<<"Yes\n";
    else cout<<"No\n";
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