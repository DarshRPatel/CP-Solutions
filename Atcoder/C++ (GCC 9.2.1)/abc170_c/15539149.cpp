#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<long long> vl;

#define F 						first
#define PB 						push_back
#define MP 						make_pair
#define f(i,a,b) 				for(ll i=a; i<b; i++)
#define rep(i,n) 				f(i,0,n)
#define w(t)					ll t; cin>>t; while(t--)
#define epsilon					1e-9

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
	// w(t) {
		ll x, n;
		cin>>x>>n;
		set<ll> s;
		ll temp;
		rep(i, n) {
			cin>>temp;
			s.insert(temp);
		}
		ll ans, i=0;
		while(true) {
			if(s.count(x-i)==0) {
				ans = x-i;
				break;
			}else if(s.count(x+i)==0) {
				ans = x+i;
				break;
			}
			i++;
		}
		cout<<ans<<"\n";
	// }
	return 0;
}