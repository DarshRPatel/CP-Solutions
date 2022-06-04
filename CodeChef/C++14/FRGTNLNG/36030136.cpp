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
		ll n, k;
		cin >> n >> k;
		string s[n];
		rep(i, n) {
			cin>>s[i];
		}
		ll flag[n] = {0}; 
		vector<string> dic(MAX);
		rep(i, k) {
			ll l;
			cin>>l;
			string temp;
			rep(j, l) {
				cin>>temp;
				dic.PB(temp);
			}
		}
		rep(i, n) {
			rep(j, dic.size()) {
				if(s[i]==dic[j]) {
					flag[i] = 1;
					break;
				}
			}
		}
		rep(i, n) {
			if(flag[i]==1) cout<<"YES ";
			else cout<<"NO ";
		}
		cout<<"\n";
	}
	return 0;
}