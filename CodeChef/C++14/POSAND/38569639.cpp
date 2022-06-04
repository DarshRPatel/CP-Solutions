#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<long long> vl;
typedef pair<long long, long long> pl;
typedef vector<vector<long long>> matrix;

#define F 						first
#define S 						second
#define PB 						push_back
#define MP 						make_pair
#define all(c) 					c.begin(), c.end()
#define f(i,a,b) 				for(ll i=a; i<b; i++)
#define rep(i,n) 				f(i,0,n)
#define fd(i, b, a)				for(ll i=b; i>=a; i--)
#define repr(i,n)				fd(i, n-1, 0)
#define tr(c,i) 				for(typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define present(c,x) 			(c.find(x) != c.end())	//for set and map
#define cpresent(c,x) 			(find(all(c),x) != c.end())	//for vectors
#define w(t)					ll t; cin>>t; while(t--)
#define ps(num, places)			fixed<<setprecision(places)<<num //use as cout<<ps(x, y)<<"\n";
#define sz(x) 					(ll)(x).size()
#define lb						lower_bound
#define ub						upper_bound
#define nl						"\n"

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
	ll n;
	cin >> n;
	ll tmp = log(n)/log(2);
	ll num = binpow(2, tmp);
	if((tmp!=0 && num==n) || num*2==n) cout<<"-1\n";
	else if(n==1) cout<<"1\n";
	else if(n==3) cout<<"1 3 2\n";
	else if(n==5) cout<<"2 3 1 5 4\n";
	else if(n==6) cout<<"1 3 2 6 4 5\n";
	else if(n==7) cout<<"1 3 2 6 4 5 7\n";
	else {	//n>=9
		vl a;
		a.PB(1), a.PB(3), a.PB(2), a.PB(6), a.PB(4), a.PB(5), a.PB(7);
		ll cnt = 7, limit = 16;
		while(true) {
			ll tmp = cnt+2;
			a.PB(tmp), a.PB(tmp-1);
			if(tmp==n) break;
			else {
				tmp++;
				ll upper = min(n, limit-1);
				f(i, tmp, upper+1) {
					a.PB(i);
				}
				if(upper==n) break;
				cnt = limit-1;
				limit *= 2;
			}
		}
		rep(i, sz(a)) cout<<a[i]<<" ";
		cout<<"\n";
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.precision(10);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	ll tests;
	cin >> tests;
	while(tests--) {
		runcase();
	}
	return 0;
}