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
		ll n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		ll zero = 0, ones = 0;
		rep(i, s.length()) {
			if(s[i]=='0') zero++;
			else ones++;
		}
		ll p = n/k;
		if(zero%p!=0 || ones%p!=0) cout<<"IMPOSSIBLE\n";
		else if(p==1) {
			string ans = "";
			rep(i, zero) ans += "0";
			rep(i, ones) ans += "1";
			cout<<ans<<"\n";
		}else {
			string str = "";
			ll a = zero/p, b = ones/p;
			rep(i, a) str += "0";
			rep(i, b) str += "1";
			string rev_str = str;
			reverse(all(rev_str));
			string s1 = str+rev_str, s2 = rev_str+str;
			string tmp = min(s1, s2); 
			string ans = "";
			rep(i, p/2) {
				ans += tmp;
			}
			if(p%2!=0) ans += tmp.substr(0, tmp.length()/2);
			cout<<ans<<"\n";
		}
	}
	return 0;
}