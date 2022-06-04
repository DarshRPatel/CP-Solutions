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
	if(a.S==b.S) return (a.F>b.F);
	else return (a.S>b.S);

}

int main() {
	doublade();
	w(t) {
		ll n;
		cin >> n;
		vl a(n);
		rep(i, n) {
			cin>>a[i];
		}
		vector<pl> len;
		ll cnt = (a[0]==0) ? 1 : 0;
		bool flag = cnt;
		f(i, 1, n) {
			if(flag) {
				if(a[i]==0) cnt++;
				else {
					ll type = cnt%2;
					len.PB({cnt, type});
					cnt = 0;
					flag = false;
				}
			}else {
				if(a[i]==0) {
					cnt++;
					flag = true;
				}
			}
		}
		sort(all(len), comp);
		// cout<<"----------\n";
		// for(auto x:len) cout<<x.F<<" "<<x.S<<"\n";
		ll p1 = 0, p2 = 0;
		if(len.empty() || len[0].S==0) cout<<"No\n";
		else {
			p1 = ceil((float)len[0].F/2);
			f(i, 1, len.size()) {
				p2 = max(p2, len[i].F);
			}
			// cout<<p1<<" "<<p2<<"\n";
			if(p1>p2) cout<<"Yes\n";
			else cout<<"No\n";
		}
		//subtask
		// ll p1 = 0, p2 = 0, len = n-2;
		// p1 = ceil((float)len/2);
		// p2 = len - p1;
		// if(p1>p2) cout<<"Yes\n";
		// else cout<<"No\n";

	}
	return 0;
}