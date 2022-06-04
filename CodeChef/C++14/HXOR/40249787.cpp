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

void runcase() {
    ll n, x;
    cin >> n >> x;
    matrix a(n, vl(30, 0));
    rep(i, n) {
        ll num;
        cin >> num;
        rep(j, sz(a[i])) {
            if(num&(1<<j)) a[i][sz(a[i])-j-1] = 1;
        }
    }
    ll cnt = 0;
    rep(i, n-1) {
        rep(j, sz(a[i])) {
            if(a[i][j]) {
                a[i][j] = 0;
                bool flag = 0;
                f(k, i+1, n) {
                    if(a[k][j]) {
                        a[k][j] = 0;
                        flag = 1;
                        break;
                    }
                }
                if(!flag) a[n-1][j] = 1;
                cnt++;
            }
            if(cnt==x) break;
        }
        if(cnt==x) break;
    }
    // cout<<cnt<<"\n";
    if(cnt<x) {
        if(n==2) {
            if((x-cnt)%2!=0) {
                a[n-2][29] = 1;
                a[n-1][29] = (a[n-1][29]) ? 0 : 1;
            }
        }else {
            if((x-cnt)%2!=0) {
                if((x-cnt)==1) {
                    a[n-2][29] = 1;
                    a[n-1][29] = (a[n-1][29]) ? 0 : 1;
                }
            }
        }
    }
    // rep(i, n) {
    //     rep(j, sz(a[i])) cout<<a[i][j];
    //     cout<<"\n";
    // }
    rep(i, n) {
        ll tmp = 0;
        repr(j, sz(a[i])) if(a[i][j]) tmp += binpow(2, sz(a[i])-j-1);
        cout<<tmp<<" ";
    }
    cout<<"\n";
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