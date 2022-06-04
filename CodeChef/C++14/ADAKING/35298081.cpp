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
		ll k;
		cin>>k;
		cout<<"O";
		ll j=1, t = k-1;
		while(t--) {
			if(j==7) {
				cout<<".\n";
				j=0;
			}else {
				cout<<".";
				j++;
			}
		}
		t = 64 - 1 - (k-1);
		while(t--) {
			if(j==7) {
				cout<<"X\n";
				j=0;
			}else {
				cout<<"X";
				j++;
			}
		}
	}
	return 0;
}