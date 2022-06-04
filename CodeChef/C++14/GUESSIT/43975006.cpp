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

const ll N = 1e6+5;
vl spf(N, -1), num;

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

void init() {
    spf[1] = 1;
    f(i, 2, N) {
        if(spf[i]==-1) {
            for(ll j=i; j<N; j+=i) {
                if(spf[j]==-1) spf[j] = i;
            }
        }
    }

    num.PB(1);
    f(i, 2, 1e6+1) {
        ll res = 1, tmp = i;
        while(tmp>=2) {
            ll p = spf[tmp], cnt = 0;
            while(tmp%p==0) {
                tmp /= p;
                cnt++;
            }
            res *= (cnt+1);
        }
        if(res%2) num.PB(i);
    }
}

void runcase() {
    for(auto x:num) {
        cout<<x<<endl;
        ll z;
        cin >> z;
        if(z==1) return;
        else if(z==-1) exit(0);
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
    init();
    // cout<<sz(num)<<"\n";
    // for(auto x:num) cout<<x<<" ";
    // cout<<"\n";
    while(tests--) {
        runcase();
    }

    return 0;
}