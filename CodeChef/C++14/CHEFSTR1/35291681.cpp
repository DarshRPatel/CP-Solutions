#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<long long> vl;

#define F 						first
#define S 						second
#define PB 						push_back
#define MP 						make_pair
#define f(i,a,b) 				for(ll i=a; i<b; i++)
#define rep(i,n) 				f(i,0,n)
#define w(t)					ll t; cin>>t; while(t--)
#define N 						10

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
		cin>>n;
		ll s[n];
		rep(i, n) {
			cin>>s[i];
		}
		ll ans = 0;
		f(i, 1, n) {
			ans += abs(s[i]-s[i-1]) - 1;
		}
		cout<<ans<<"\n";
	}
	return 0;
}