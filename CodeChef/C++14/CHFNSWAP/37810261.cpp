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
#define MOD						(ll)1e9

void doublade() {
	ios::sync_with_stdio(false); cin.tie(0); cout.precision(10);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

int main() {
	doublade();
	w(t) {
		ll n;
		cin >> n;
		ll half = (n*(n+1))/2;
		if(half%2!=0) cout<<"0\n";
		else {
			half /= 2;
			ll lowm = ceil((double)(-2.0+sqrt(4.0+8*(n*n-3*n)))/4.0), uppm = (-2.0+sqrt(4.0+8*(n*n+n)))/4.0;
			ll ans = 0;
			f(i, lowm-1, uppm+2) {
				ll m = i+1, o1 = m*(m+1)/2, diff = half-o1;
				if(diff>=0) {
					ll low = max((ll)1, m+1-diff), upp = min(m, n-diff);
					if(upp>=low) ans += upp-low+1;
				}
			}
			ll m = (-1+sqrt(1+2*n*(n+1)))/2;
			if(m>=2 && (m*(m+1))==(n*(n+1))/2) {
				ans += (m*(m-1))/2;
				m = n-m;
				if(m>=2) ans += (m*(m-1))/2;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}