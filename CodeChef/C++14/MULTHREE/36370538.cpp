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
		ll k, d[7];
		cin >> k >> d[0] >> d[1];

		d[2] = (d[0]+d[1])%10;
		d[3] = (2*d[2])%10;
		d[4] = (4*d[2])%10;
		d[5] = (8*d[2])%10;
		d[6] = (6*d[2])%10;
		ll q = (k-3)%4, p = (k-3)/4;
		ll ans = (d[0]+d[1]+d[2])%3;
		if(q==1) ans += d[3]%3;
		else if(q==2) ans += (d[3]+d[4])%3;
		else if(q==3) ans += (d[3]+d[4]+d[5])%3; // q==3
		ans += ( (p%3) * ((d[3]+d[4]+d[5]+d[6]) % 3) ) % 3;

		if(ans%3==0) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}