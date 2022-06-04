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

bool comp(const pl &a, const pl &b) {
	return (a.F>b.F);
}

int main() {
	doublade();
	w(t) {
		ll n, m;
		cin >> n >> m;
		matrix a(m+1, vl(n));
		rep(i, n) {
			cin>>a[0][i];
		}
		rep(i, n) {
			f(j, 1, m+1) {
				ll in;
				cin >> in;
				a[j][i] = in + a[j-1][i];
			}
		}
		// rep(i, n) {
		// 	f(j, 1, m+1) cout<<a[j][i]<<" ";
		// 	cout<<"\n";
		// }

		// vl rat(n, 0);
		// f(i, 1, m+1) {
		// 	ll pos = 0, tmp = a[i][0];
		// 	f(j, 1, n) {
		// 		if(a[i][j]>tmp) {
		// 			tmp = a[i][j];
		// 			pos = j;
		// 		}
		// 	}
		// 	if(rat[pos]==0) rat[pos] = i;
		// }
		vl rat(n, 0);
		rep(i, n) {
			ll tmp = a[1][i], pos = 1;
			f(j, 2, m+1) {
				if(a[j][i]>tmp) {
					tmp = a[j][i];
					pos = j;
				}
			}
			rat[i] = pos;
		}
		// for(auto x:rat) cout<<x<<" ";
		// cout<<"\n";

		// vl m_ps(n);
		// rep(i, n) {
		// 	ll tmp = a[1][i];
		// 	m_ps[i] = 1;
		// 	f(j, 2, m+1) {
		// 		if(a[j][i]>tmp) {
		// 			tmp = a[j][i];
		// 			m_ps[i] = j;
		// 		}
		// 	}
		// }
		vl m_ps(n);
		vl ran(n, n+1);
		f(i, 1, m+1) {
			vector<pl> sam;
			rep(j, n) {
				sam.PB({a[i][j], j});
			}
			sort(all(sam), comp);
			// for(auto x:sam) cout<<x.F<<" ";
			// cout<<"\n";
			ll cnt = 1, ply = sam[0].S;
			if(cnt<ran[ply]) {
				ran[ply] = cnt;
				m_ps[ply] = i;
			}
			f(j, 1, n) {
				if(sam[j-1].F>sam[j].F) cnt = j+1;
				// cout<<"cnt,j=="<<cnt<<" "<<j<<"\n";
				ply = sam[j].S;
				if(cnt<ran[ply]) {
					ran[ply] = cnt;
					m_ps[ply] = i;
				}
			}
			// for(auto x:ran) cout<<x<<" ";
			// cout<<"\n";
		}
		// for(auto x:m_ps) cout<<x<<" ";
		// cout<<"\n";
		// for(auto x:ran) cout<<x<<" ";
		// cout<<"\n";


		ll ans = 0;
		rep(i, m_ps.size()) {
			if(m_ps[i]!=rat[i]) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}