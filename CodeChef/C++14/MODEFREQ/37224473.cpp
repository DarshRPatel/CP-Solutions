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
		vl a(n);
		rep(i, n) {
			cin>>a[i];
		}
		sort(all(a));
		vl f;
		ll tmp = a[0], cnt = 1;
		f(i, 1, n) {
			if(a[i]==tmp) cnt++;
			else {
				f.PB(cnt);
				cnt = 1;
				tmp = a[i];
			}
		}
		f.PB(cnt);
		sort(all(f));
		// for(auto x:f) cout<<x<<" ";
		// cout<<"\n";
		ll ans = 0, num = 0;
		tmp = f[0], cnt = 1;
		f(i, 1, f.size()) {
			if(f[i]==tmp) cnt++;
			else {
				if(cnt>ans) {
					ans = cnt;
					num = tmp;
				}
				tmp = f[i];
				cnt = 1;
			}
		}
		if(cnt>ans) {
			ans = cnt;
			num = tmp;
		}
		cout<<num<<"\n";
	}
	return 0;
}