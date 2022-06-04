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

bool isValid(ll i, ll j, ll n, ll m) {
    if(i<0 || i>=n || j<0 || j>=m) return 0;
    return 1;
}

void runcase() {
    ll n, m, k;
    cin >> n >> m >> k;
    matrix a(n, vl(m));
    rep(i, n) {
        rep(j, m) cin >> a[i][j];
    }
    matrix b(n, vl(m, 0));
    rep(i, n) {
        rep(j, m) {
            b[i][j] = a[i][j];
            if(isValid(i-1, j, n, m)) b[i][j] += b[i-1][j];
            if(isValid(i, j-1, n, m)) b[i][j] += b[i][j-1];
            if(isValid(i-1, j-1, n, m)) b[i][j] -= b[i-1][j-1];
            // cout<<b[i][j]<<" ";
        }
        // cout<<"\n";
    }
    ll cnt = 0;
    f(l, 1, n+1) {
        fd(i, n-1, l-1) {
            fd(j, m-1, l-1) {
                ll sum = b[i][j];
                if(isValid(i, j-l, n, m)) sum -= b[i][j-l];
                if(isValid(i-l, j, n, m)) sum -= b[i-l][j];
                if(isValid(i-l, j-l, n, m)) sum += b[i-l][j-l];

                if(sum>=(k*l*l)) cnt++;
            }
        }
    }
    cout<<cnt<<"\n";
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