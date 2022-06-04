#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
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
#define tr(c,i) 				for(typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define present(c,x) 			(c.find(x) != c.end())	//for set and map
#define cpresent(c,x) 			(find(all(c),x) != c.end())	//for vectors
#define w(t)					ll t; cin>>t; while(t--)
#define epsilon 				1e-9
#define MOD						1000000007

void doublade() {
	ios::sync_with_stdio(false); cin.tie(0); cout.precision(10);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

int main() {
	doublade();
	// w(t) {
		ll n, k;
		cin >> n >> k;
		vl a(n);
		rep(i, n) {
			cin>>a[i];
		}
		ll ans = 1;
		stack<ll> s, p;
		for(ll i=n-1; i>=0; i--) {

			while(!s.empty() && s.top()>=a[i]) {
				s.pop();
				p.pop();
			}

			if(!s.empty()) {
				ans *= (p.top()-i+1)%MOD;
				ans %= MOD;
			}

			s.push(a[i]);
			p.push(i);
		}

		cout<<ans<<"\n";
	// }
	return 0;
}