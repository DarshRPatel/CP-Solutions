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

struct elem {
    ll x, y, z;
};

bool check(vl a) {
    assert(sz(a)==3);
    if((a[0]^a[1])>0 && (a[1]^a[2])>0 && ((a[0]^a[1]^a[2]) == a[1])) return 1;
    return 0;
}

bool check(vl a, ll p, ll q, ll r) {
    assert(sz(a)==3);
    a[r] = a[p]^a[q];
    if((a[0]^a[1])>0 && (a[1]^a[2])>0 && ((a[0]^a[1]^a[2]) == a[1])) return 1;
    return 0;
}

void runcase() {
    ll n;
    cin >> n;
    ll val = 0;
    vl a(n);
    rep(i, n) {
        cin >> a[i];
        val ^= a[i];
    }
    if(n==1) cout<<"0\n";
    else if(n==2) {
        if(!val) cout<<"-1\n";
        else cout<<"0\n";
    }else if(n==3) {
        if(check(a)) {
            cout<<"0\n";
            return;
        }
        if(check(a, 0, 1, 2)) {
            cout<<"1\n1 2 3\n";
            return;
        }
        if(check(a, 0, 2, 1)) {
            cout<<"1\n1 3 2\n";
            return;
        }
        if(check(a, 1, 2, 0)) {
            cout<<"1\n2 3 1\n";
            return;
        }
        cout<<"-1\n";
    }else {
        if(a[0]>0) {
            vector<elem> moves;
            moves.PB({1, 2, 3});
            moves.PB({1, 2, 4});
            moves.PB({3, 4, 2});
            f(i, 3, n+1) {
                if(i%2==1) moves.PB({1, 2, i});
                else moves.PB({1, 3, i});
            }
            cout<<sz(moves)<<"\n";
            rep(i, sz(moves)) cout<<moves[i].x<<" "<<moves[i].y<<" "<<moves[i].z<<"\n";
        }else if(a[1]>0) {
            vector<elem> moves;
            moves.PB({1, 2, 4});
            moves.PB({2, 4, 3});
            f(i, 5, n+1) {
                if(i%2==0) moves.PB({1, 2, i});
                else moves.PB({1, 3, i});
            }
            cout<<sz(moves)<<"\n";
            rep(i, sz(moves)) cout<<moves[i].x<<" "<<moves[i].y<<" "<<moves[i].z<<"\n";
        }else {
            bool flag = 0;
            vector<elem> moves;
            f(i, 2, n) {
                if(a[i]>0) {
                    moves.PB({2, i+1, 1});
                    flag = 1;
                    break;
                }
            }
            if(!flag) cout<<"-1\n";
            else {
                moves.PB({1, 2, 3});
                moves.PB({1, 2, 4});
                moves.PB({3, 4, 2});
                f(i, 3, n+1) {
                    if(i%2==1) moves.PB({1, 2, i});
                    else moves.PB({1, 3, i});
                }
                cout<<sz(moves)<<"\n";
                rep(i, sz(moves)) cout<<moves[i].x<<" "<<moves[i].y<<" "<<moves[i].z<<"\n";
            }
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
    cin >> tests;
    while(tests--) {
        runcase();
    }
    return 0;
}