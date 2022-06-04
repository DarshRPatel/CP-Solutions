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
#define MAX						1e16

constexpr ll int_pow(ll b, ll e) {
    return (e == 0) ? 1 : b * int_pow(b, e - 1);
}

void doublade() {
	ios::sync_with_stdio(false); cin.tie(0); cout.precision(10);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

int main()
{
	doublade();
	w(t) {
		ll n;
		cin >> n;
		ll a[n];
		rep(i, n) {
			cin>>a[i];
		}
		vector<pl> sb(n+1);
		sb[0] = MP(0, 0);
		f(i, 1, n+1) {
			sb[i] = MP((sb[i-1].F + (a[i-1] % n)) % n, i);
		}
		sort(all(sb));
		ll pos1, pos2;
		f(i, 1, n+1) {
			if(sb[i].F==sb[i-1].F) {
				pos2 = sb[i].S;
				pos1 = sb[i-1].S;
				break;
			}
		}
		cout<<pos2-pos1<<"\n";
		for(ll i=pos1; i<pos2; i++) {
			cout<<i+1<<" ";
		}
		cout<<"\n";
	}
	return 0;
}