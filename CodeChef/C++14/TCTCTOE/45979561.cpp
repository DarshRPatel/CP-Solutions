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

const ll N = 3;
char a[3][3];
map<char, ll> win;

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

void solve(char c) {
    if(a[0][0]==c && a[1][0]==c && a[2][0]==c) win[c] = 1;
    if(a[0][1]==c && a[1][1]==c && a[2][1]==c) win[c] = 1;
    if(a[0][2]==c && a[1][2]==c && a[2][2]==c) win[c] = 1;
    if(a[0][0]==c && a[0][1]==c && a[0][2]==c) win[c] = 1;
    if(a[1][0]==c && a[1][1]==c && a[1][2]==c) win[c] = 1;
    if(a[2][0]==c && a[2][1]==c && a[2][2]==c) win[c] = 1;
    if(a[0][0]==c && a[1][1]==c && a[2][2]==c) win[c] = 1;
    if(a[0][2]==c && a[1][1]==c && a[2][0]==c) win[c] = 1;
}

void runcase() {
    ll cnt[2] = {0};
    win['X'] = win['O'] = 0;
    rep(i, 3) {
        rep(j, 3) {
            cin >> a[i][j];
            if(a[i][j]=='X') cnt[0]++;
            else if(a[i][j]=='O') cnt[1]++;
        }
    }
    if(abs(cnt[0]-cnt[1])<=1 && cnt[0]>=cnt[1]) {
        solve('X');
        solve('O');
        if(!win['X'] && !win['O']) {
            ll rem = 9-cnt[0]-cnt[1], ans = (rem) ? 2 : 1;
            cout<<ans<<"\n";
        }else if(!win['O']) {
            ll ans = (cnt[0]>cnt[1]) ? 1 : 3;
            cout<<ans<<"\n";
        }else if(!win['X']) {
            ll ans = (cnt[0]==cnt[1]) ? 1 : 3;
            cout<<ans<<"\n";
        }else cout<<"3\n";
    }else cout<<"3\n";
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