#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<long long> vl;
typedef pair<long long, long long> pl;
typedef vector<vector<long long>> matrix;
// typedef tree<int, null_type, less, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

set<ll> sa;

ll findans(ll x) {	//for type 2 query
	auto it = sa.upper_bound(x);
	it--;
	return (*it);
}

int main() {
	doublade();
	// w(t) {
		ll n, q;
		cin >> n >> q;
		vl a(n+1);
		f(i, 1, n+1) {
			cin>>a[i];
		}
		sa.insert(1);
		f(i, 2, n) {
			if(a[i]%a[i-1]!=0) sa.insert(i);
		}
		while(q--) {
			ll type, index;
			cin>>type>>index;
			if(type==1) {
				cin>>a[index];
				if(index>1) {
					if((findans(index)==index) && (a[index]%a[index-1]==0)) {
						sa.erase(index);
					}else if((findans(index)<index) && (a[index]%a[index-1]!=0)) {
						sa.insert(index);
					}
				}

				if(index<n) {
					if((findans(index+1)==index+1) && (a[index+1]%a[index]==0)) {
						sa.erase(index+1);
					}else if((findans(index+1)<index+1) && (a[index+1]%a[index]!=0)) {
						sa.insert(index+1);
					}
				}
			}else {
				cout<<findans(index)<<"\n";
			}
		}
		
	// }
	return 0;
}