#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<long long> vl;
typedef pair<long long, long long> pl;
typedef vector<pl> vpl;
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
	// w(t) {
		ll n;
		cin >> n;
		vpl points;
		points.PB(MP(0, 0));
		rep(i, n) {
			ll x, y;
			cin>>x>>y;
			points.PB(MP(x, y));
		}
		points.PB(MP(100000, 0));
		// rep(i, points.size()) cout<<points[i].F<<" "<<points[i].S<<"\n";
		sort(all(points));
		ll ans = 0;
		f(y, 1, 501) {
			ll prev = 0;
			f(i, 1, points.size()) {
				if(points[i].S>=y) continue;
				else {
					ll width = points[i].F - prev;
					ans = max(ans, width*y);
					prev = points[i].F;
				}
			}
		}
		cout<<ans<<"\n";
	// }
	return 0;
}