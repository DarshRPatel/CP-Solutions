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
		string s, p;
		cin >> s >> p;
		ll cnt[26] = {0};
		rep(i, s.length()) {
			cnt[s[i] - 'a'] += 1;
		}
		rep(i, p.length()) {
			cnt[p[i] - 'a'] -= 1;
		}
		string ans = "";
		ll temp = p[0] - 'a';
		for(ll i=0; i<temp; i++) {
			rep(j, cnt[i]) {
				ans += (char)(i+'a');
			}
		}
		char c = temp+'a';
		string sample = "";
		rep(i, cnt[temp]) sample += c;
		string s1 = sample + p, s2 = p + sample;
		ans += (s1<=s2) ? s1 : s2;
		for(ll i=temp+1; i<26; i++) {
			rep(j, cnt[i]) {
				ans += (char)(i+'a');
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}