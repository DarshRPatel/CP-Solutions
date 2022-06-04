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
    ll N, E, H, A, B, C;
    cin >> N >> E >> H >> A >> B >> C;
    if(E<N && H<N) cout<<"-1\n";
    else if(E<N && H<(3*N-2*E)) cout<<"-1\n";
    else if(H<N && E<(2*N-H)) cout<<"-1\n";
    else {
        ll cost = LLONG_MAX;
        if(E==0) cost = N*B;
        else if(H==0) cost = N*A;
        else {
            if(A==min(A, min(B, C))) {
                for(ll i=0; 2*i<=E && i<=N; i++) {
                    vl items{i, 0, 0};
                    ll rem = N-i, e = E-2*i, h = H;
                    ll b_max = h/3, c_max = min(e, h);
                    if( (c_max+ max(0LL, (h-c_max)/3) )>=rem ) {
                        if(B<=C) {
                            items[1] = min(rem, b_max);
                            h -= items[1]*3;
                            items[2] = min(rem-items[1], min(e, h));
                            h -= items[2];
                            if( (items[1]+items[2])<rem ) {
                                rem -= (items[1]+items[2]);
                                ll remove = (rem-h)/2;
                                if((h+3*remove)<(remove+rem)) remove++;
                                items[1] -= remove;
                                items[2] += (remove+rem);
                            }
                        }else {
                            items[2] = min(c_max, rem);
                            e -= items[2], h -= items[2];
                            items[1] = min(rem-items[2], h/3);
                            if( (items[1]+items[2])<rem ) {
                                rem -= (items[1]+items[2]);
                                ll remove = (h-3*rem)/2;
                                items[1] += (remove+rem);
                                items[2] -= remove;
                            }
                        }
                        ll sum = items[0]+items[1]+items[2];
                        if(sum==N && min(min(items[0], items[1]), items[2])>=0) {
                            ll tmpC = 0;
                            tmpC += items[0]*A;
                            tmpC += items[1]*B;
                            tmpC += items[2]*C;
                            // if(tmpC<cost) {
                            //     cout<<"A ";
                            //     for(auto x:items) cout<<x<<" ";
                            //     cout<<tmpC<<"\n";
                            // }
                            cost = min(cost, tmpC);
                        }
                    }
                }
            }
            if(B==min(A, min(B, C))) {
                for(ll i=0; 3*i<=H && i<=N; i++) {
                    vl items{0, i, 0};
                    ll rem = N-i, e = E, h = H-3*i;
                    ll a_max = e/2, c_max = min(e, h);
                    if( (c_max+ max(0LL, (e-c_max)/2) )>=rem ) {
                        if(A<=C) {
                            items[0] = min(rem, a_max);
                            e -= items[0]*2;
                            items[2] = min(rem-items[0], min(e, h));
                            e -= items[2];
                            if( (items[0]+items[2])<rem ) {
                                rem -= (items[0]+items[2]);
                                ll remove = rem-e;
                                items[0] -= remove;
                                items[2] += (remove+rem);
                            }
                        }else {
                            items[2] = min(c_max, rem);
                            e -= items[2], h -= items[2];
                            items[0] = min(rem-items[2], e/2);
                            if( (items[0]+items[2])<rem ) {
                                rem -= (items[0]+items[2]);
                                ll remove = (e-2*rem);
                                items[0] += (remove+rem);
                                items[2] -= remove;
                            }
                        }
                        ll sum = items[0]+items[1]+items[2];
                        if(sum==N && min(min(items[0], items[1]), items[2])>=0) {
                            ll tmpC = 0;
                            tmpC += items[0]*A;
                            tmpC += items[1]*B;
                            tmpC += items[2]*C;
                            // if(tmpC<cost) {
                            //     cout<<"B ";
                            //     for(auto x:items) cout<<x<<" ";
                            //     cout<<tmpC<<"\n";
                            // }
                            cost = min(cost, tmpC);
                        }
                    }
                }
            }
            if(C==min(A, min(B, C))) {
                for(ll i=0; i<=min(E, H) && i<=N; i++) {
                    vl items{0, 0, i};
                    ll rem = N-i, e = E-i, h = H-i;
                    ll a_max = e/2, b_max = h/3;
                    if( (a_max+b_max)>=rem ) {
                        if(A<=B) {
                            items[0] = min(a_max, rem);
                            items[1] = rem-items[0];
                        }else {
                            items[1] = min(b_max, rem);
                            items[0] = rem-items[1];
                        }
                        ll sum = items[0]+items[1]+items[2];
                        if(sum==N && min(min(items[0], items[1]), items[2])>=0) {
                            ll tmpC = 0;
                            tmpC += items[0]*A;
                            tmpC += items[1]*B;
                            tmpC += items[2]*C;
                            // if(tmpC<cost) {
                            //     cout<<"C ";
                            //     for(auto x:items) cout<<x<<" ";
                            //     cout<<tmpC<<"\n";
                            // }
                            cost = min(cost, tmpC);
                        }
                    }
                }
            }
        }
        cout<<cost<<"\n";
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