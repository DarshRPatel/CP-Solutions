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
	// w(t) {
		ll n;
		cin >> n;
		ll ans[4] = {0, 0, 0, 0}, cnt=0, pos=0;
		vl s(n);
		rep(i, n) {
			cin>>s[i];
			if(s[i]==1) cnt++;
			else cnt--;

			if(cnt>ans[0]) {
				ans[0] = cnt;
				ans[1] = i+1;
			}

			if(cnt==0) {
				if(i+1-pos>ans[2]) {
					ans[2] = i+1-pos;
					ans[3] = pos+1;
				}
				pos = i+1;
			}
		}
		rep(i, 4) {
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
		return 0;
	// }
}