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

bool comp(pl a, pl b) {
	return (a.S-a.F<=b.S-b.F);
}

// ll lower_bound(const vl &a, ll num) {
// 	ll l=0, r=a.size()-1, ans = 0;
// 	while(l<=r) {
// 		ll mid = l + (r-l)/2;
// 		if(a[mid]<=num) {
// 			ans = mid;
// 			l = mid+1;
// 		}else r = mid-1;
// 	}
// 	return ans;
// }

int main() {
	doublade();
	// w(t) {
		ll n, l1, l2;
		cin >> n >> l1 >> l2;
		vector<pl> a(n);
		vl a1(l1), a2(l2);
		rep(i, n) {
			cin>>a[i].F>>a[i].S;
		}
		rep(i, l1) {
			cin>>a1[i];
		}
		rep(i, l2) {
			cin>>a2[i];
		}
		sort(all(a), comp);
		sort(all(a1));
		sort(all(a2));
		ll time = LLONG_MAX;
		// rep(i, n) {
		// 	ll t2 = upper_bound(all(a2), a[i].S) - a2.begin();
		// 	if(t2==l2) t2 = continue;
		// 	if(a2[t2]<a[i].S) continue;
		// 	ll t1 = lower_bound(all(a1), a[i].F) - a1.begin();
		// 	// ll t1 = lower_bound(a1, a[i].F);
		// 	if(a1[t1]!=a[i].F || t1==l1) t1--;
		// 	if(a1[t1]>a[i].F) continue;
		// 	// cout<<a1[t1]<<" "<<a2[t2]<<"\n";
		// 	ll temp = a2[t2] - a1[t1] + 1;
		// 	time = min(time, temp);
		// }
		rep(i, n) {
			vl::iterator intime, outtime;
			if (a[i].S - a[i].F >= time) break;
			intime = lower_bound(all(a1), a[i].F);
			outtime = lower_bound(all(a2), a[i].S);
			if(*intime != a[i].F || intime == a1.end()) intime--;
			if(outtime == a2.end()) continue;
			time = min(time, (*outtime-*intime+1));
		}
		cout<<time<<"\n";
	// }
	return 0;
}