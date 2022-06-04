#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<long long> vl;
typedef pair<long long, long long> pl;

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
#define MAX						2500

constexpr ll int_pow(ll b, ll e) {
    return (e == 0) ? 1 : b * int_pow(b, e - 1);	// returns b^e
}

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
		string s;
		cin>>s;
		ll n = s.length(), len = floor(n/2);
		string s1 = s.substr(0, len);
		string s2 = s.substr(ceil((float)n/2), len);
		sort(s1.begin(), s1.begin()+len);
		sort(s2.begin(), s2.begin()+len);
		bool flag = true;
		rep(i, len) {
			if(s1[i]!=s2[i]) {
				flag = false;
				break;
			}
		}
		if(flag) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}