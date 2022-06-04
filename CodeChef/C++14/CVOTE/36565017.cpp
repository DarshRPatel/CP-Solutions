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
#define MOD						1000000007

void doublade() {
	ios::sync_with_stdio(false); cin.tie(0); cout.precision(10);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

bool comp_string(pair<string, string> a, pair<string, string> b) {
	return (a.F==b.F) ? (a.S<b.S) : (a.F<b.F);
}

bool comp(pair<pair<string, string>, ll> a, pair<pair<string, string>, ll> b) {
	if(a.S==b.S) {
		if(a.F.F==b.F.F) return (a.F.S < b.F.S);
		else return (a.F.F < b.F.F);
	}else return (a.S < b.S);
}

int main() {
	doublade();
// 	w(t) {
		ll n, m;
		cin >> n >> m;
		map<string, string> X;
		map<string, ll> Y;
		map<string, ll> Z;
		rep(i, n) {
			string chef, country;
			cin >> chef >> country;
			X.insert({chef, country});
		}
		rep(i, m) {
			string s;
			cin >> s;
			Y[X[s]] +=1;
			Z[s] += 1;
		}
		ll maxV=0;
		string chef, country;
		for(auto it=Z.begin(); it!=Z.end(); it++) {
			if(it->S > maxV) {
				chef = it->F;
				maxV = it->S;
			}
		}
		maxV=0;
		for(auto it=Y.begin(); it!=Y.end(); it++) {
			if(it->S > maxV) {
				country = it->F;
				maxV = it->S;
			}
		}
		cout<<country<<"\n"<<chef<<"\n";
// 	}
	return 0;
}