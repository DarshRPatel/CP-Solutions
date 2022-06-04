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
		ll n;
		cin >> n;		
		ll ans[4] = {0};
		string s;
		rep(i, n) {
			cin>>s;
			if(s=="AC") ans[0] += 1;
			else if(s=="WA") ans[1] += 1;
			else if(s=="TLE") ans[2] += 1;
			else ans[3] += 1;	// s=="RE"
		}
		cout<<"AC x "<<ans[0]<<"\n";
		cout<<"WA x "<<ans[1]<<"\n";
		cout<<"TLE x "<<ans[2]<<"\n";
		cout<<"RE x "<<ans[3]<<"\n";
	// }
	return 0;
}