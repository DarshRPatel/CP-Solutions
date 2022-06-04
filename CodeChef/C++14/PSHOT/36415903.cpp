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
		string s;
		cin >> s;
		ll ans, t1=0, t2=0;
		rep(i, s.length()) {
			ans = i+1;
			if(i%2==0) {
				t1 += (s[i]=='1') ? 1 : 0;
				if(t1>t2) {
					ll temp = t2 + ceil((2*n-i-1)/(2.0));
					if(t1>temp) break;
				}else if(t2>t1) {
					ll temp = t1 + (2*n-i-1)/2;
					if(t2>temp) break;
				}
			}else {
				t2 += (s[i]=='1') ? 1 : 0;
				if(t1>t2) {
					ll temp = t2 + (2*n-i-1)/2;
					if(t1>temp) break;
				}else if(t2>t1) {
					ll temp = t1 + (2*n-i-1)/2;
					if(t2>temp) break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}