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

const ll N = 1e6+1;
vl isprime(N, 1), prime, SPF(N), totalPrimes(N, 0); 

void seive() { 
    isprime[0] = isprime[1] = 0; 
    f(i, 2, N) {
        if(isprime[i]) { 
            prime.push_back(i);
            SPF[i] = i; 
        }
        for(ll j=0; j<(ll)prime.size() && i*prime[j]<N && prime[j]<=SPF[i]; j++) { 
            isprime[i*prime[j]]=false;
            SPF[i*prime[j]] = prime[j]; 
        } 
    } 
}

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

void precompute() {
    seive();
    ll cnt = 0;
    f(i, 2, N) {
        if(isprime[i]) cnt++;
        totalPrimes[i] = cnt;
    }
}

void runcase() {
    ll x, y;
    cin >> x >> y;
    ll cnt = totalPrimes[x];
    if(cnt<=y) cout<<"Chef\n";
    else cout<<"Divyam\n";
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