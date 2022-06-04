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

void foo(ll n) {
    if(n==0) cout<<"0\n";
    else if(n>0) cout<<"POSITIVE\n";
    else cout<<"NEGATIVE\n";
}

void runcase() {
    ll n, q;
    cin >> n >> q;
    set<ll> s;
    vl a(n);
    rep(i, n) {
        cin >> a[i];
        s.insert(a[i]);
    }
    sort(all(a));
    while(q--) {
        ll x;
        cin >> x;
        if(s.count(x)) foo(0);
        else {
            ll small = upper_bound(all(a), x)-a.begin(), neg = n-small;
            if(neg%2==0) foo(1);
            else foo(-1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.precision(10);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ll tests = 1;
    // cin >> tests;
    while(tests--) {
        runcase();
    }
    return 0;
}