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
#define ps(ans, len)			cout<<fixed<<setprecision(len)<<ans<<"\n";
#define epsilon 				(double)1e-9
#define MOD						(ll)1e9

void doublade() {
	ios::sync_with_stdio(false); cin.tie(0); cout.precision(10);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

bool isValid(const vl &a, double mid, ll d) {
	double tmp = 0.0;
	rep(i, a.size()) {
		if(tmp<=a[i]) {
			tmp = a[i]+mid;
		}else {
			if(tmp<=(a[i]+d)) {
				tmp += mid;
			}else return false;
		}
	}
	return true;
}

double solve(const vl &a, ll d, double l, double r) {
	double ans = l;
	rep(i, 101) {
		double mid = l + (r-l)/2;
		if(isValid(a, mid, d)) {
			ans = mid;
			l = mid;
		}else r = mid;
	}
	return ans;
}

int main() {
	doublade();
	w(t) {
		ll n, d;
		cin >> n >> d;
		vl a(n);
		rep(i, n) {
			cin>>a[i];
		}
		sort(all(a));
		double l = 0, r = 1e18;
		double ans = solve(a, d, l, r);
		cout << fixed << setprecision(6) << ans <<"\n";
	}
	return 0;
}