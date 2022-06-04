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

bool isValid(string s, string t) {
    ll n = s.length(), m = t.length(), i=0, j=0;
    while(i<n && j<m) {
        if(s[i]==t[j]) j++;
        i++;
    }
    return (j==m) ? 1 : 0;
}

void runcase() {
    string s;
    cin >> s;
    ll n = s.length();
    bool flag = 0;
    rep(i, n) {
        if(s[i]=='0') {
            flag = 1;
            break;
        }
    }
    if(!flag) cout<<"0\n";
    else {
        ll pos = -1;
        matrix next(2, vl(n));
        rep(i, n) {
            if(s[i]=='0') {
                f(j, pos+1, i+1) next[0][j] = i;
                pos = i;
            }
        }
        f(j, pos+1, n) next[0][j] = n;
        pos = -1;
        rep(i, n) {
            if(s[i]=='1') {
                f(j, pos+1, i+1) next[1][j] = i;
                pos = i;
            }
        }
        f(j, pos+1, n) next[1][j] = n;
        // rep(i, n) cout<<next[0][i]<<" ";
        // cout<<"\n";
        // rep(i, n) cout<<next[1][i]<<" ";
        // cout<<"\n";
        matrix dp(2, vl(n+2, 0));
        dp[0][n] = dp[0][n+1] = 0;
        dp[1][n] = dp[1][n+1] = 0;
        repr(i, n) {
            dp[0][i] = dp[0][i+1];
            dp[1][i] = dp[1][i+1];
            if(s[i]=='0' && next[1][i]<n) dp[0][i] = max(dp[0][i], 1+dp[0][next[1][i]+1]);
            if(s[i]=='1' && next[0][i]<n) dp[0][i] = max(dp[0][i], 1+dp[0][next[0][i]+1]);
            if(next[1][i]<n) dp[1][i] = max(dp[1][i], 1+dp[0][next[1][i]+1]);
        }
        // rep(i, n) cout<<dp[0][i]<<" ";
        // cout<<"\n";
        // rep(i, n) cout<<dp[1][i]<<" ";
        // cout<<"\n";
        ll len = dp[1][0]+1, idx = next[1][0]+1;
        string ans = "1";
        f(i, 1, len) {
            if(idx>=n) {
                ans += '0';
                continue;
            }
            if(next[0][idx]>=n) {
                ans += '0';
                idx = next[0][idx]+1;
                continue;
            }

            if(dp[0][next[0][idx]+1]<len-i-1) {
                ans += '0';
                idx = next[0][idx]+1;
            }else {
                ans += '1';
                idx = next[1][idx]+1;
            }
        }
        cout<<ans<<"\n";
    }
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