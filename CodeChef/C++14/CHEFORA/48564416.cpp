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

const ll N = 1e5+1;
vl arr, pref;

bool comp(ll a, ll b) {
    return (a > b);
}

ll binpow(ll a, ll b) {
    ll res = 1;
    a  %= MOD;
    while(b>0) {
        if(b&1) (res *= a)%=MOD;
        (a *= a)%=MOD;
        b >>= 1;
        a %= MOD;
        res %= MOD;
    }
    return res;
}

void precompute() {
    auto foo = [](ll num) {
        ll x = num;
        if(x<10) {
            arr.PB(x);
            return;
        }
        string s = "";
        while(x) {
            s += ('0'+x%10);
            x /= 10;
        }
        ll n = s.length();
        string t = s.substr(1);
        reverse(all(t));
        ll res = 0, pow = 1;
        rep(i, sz(t)) {
            res += ((t[i]-'0')*pow);
            pow *= 10;
        }
        res += (num*pow);
        arr.PB(res);
    };
    f(i, 1, N) foo(i);
    pref = arr;
    f(i, 1, sz(arr)) (pref[i] += pref[i-1])%=(MOD-1);
}

void runcase() {
    ll l, r;
    cin >> l >> r;
    l--, r--;
    ll res = arr[l], power = pref[r]-pref[l];
    while(power<0) (power += (MOD-1))%=(MOD-1);
    res = binpow(res, power);
    cout<<res<<"\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.precision(10);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ll tests = 1;
    cin >> tests;
    precompute();
    while(tests--) {
        runcase();
    }
    return 0;
}