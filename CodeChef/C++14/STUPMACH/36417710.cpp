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

// int main() {
// 	doublade();
// 	w(t) {
// 		ll n;
// 		cin >> n;
// 		ll pos, m = LLONG_MAX;
// 		vl s(n);
// 		rep(i, n) {
// 			cin>>s[i];
// 			if(s[i]<m) {
// 				m = s[i];
// 				pos = i;
// 			}
// 		}
// 		ll tokens = m*n;
// 		ll min_total = m;
// 		while(pos>0) {
// 			m = LLONG_MAX;
// 			ll temp_pos = 0;
// 			for(ll i=0; i<pos; i++) {
// 				if(s[i]-min_total<m) {
// 					m = s[i]-min_total;
// 					temp_pos = i;
// 				}
// 			}
// 			tokens += m*pos;
// 			min_total += m;
// 			pos = temp_pos;
// 		}
// 		cout<<tokens<<"\n";
// 	}
// 	return 0;
// }

int main() {
	doublade();
	w(t) {
		ll n;
		cin >> n;
		vl s(n);
		rep(i, n) {
			cin>>s[i];
		}
		ll tokens = s[0], old_lim = s[0];
		f(i, 1, n) {
			if(s[i]<old_lim) old_lim = s[i];
			tokens += old_lim;
		}
		cout<<tokens<<"\n";
	}
}