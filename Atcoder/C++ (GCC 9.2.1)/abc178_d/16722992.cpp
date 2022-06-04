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
// #define MOD						(ll)1e9

void doublade() {
	ios::sync_with_stdio(false); cin.tie(0); cout.precision(10);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

const ll MOD = 1e9+7;

int main() {
	doublade();
	// w(t) {
		ll s;
		cin >> s;
		vl poss(s+1, 0);
		poss[3] = poss[4] = poss[5] = 1, poss[6] = 2;
		f(i, 7, s+1) {
			poss[i] = 1;
			for(ll j=3; j+3<=i; j++) {
				poss[i] += poss[j]%MOD;
				poss[i] %= MOD;
			}
			poss[i] %= MOD;
		}
		cout<<poss[s]<<"\n";
	// }
	return 0;
}