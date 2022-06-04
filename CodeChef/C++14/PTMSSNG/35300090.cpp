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
		ll size = 4*n - 1;
		ll x[size], y[size];
		rep(i, size) {
			cin>>x[i]>>y[i];
		}
		sort(x, x+size);
		sort(y, y+size);
		ll p[2] = {0};
		for(ll i=0; i<size; i+=2) {
			if(i==size-1) {
				p[0] = x[i];
				break;
			}
			if(x[i]!=x[i+1]) {
				p[0] = x[i];
				break;
			}
		}
		for(ll i=0; i<size; i+=2) {
			if(i==size-1) {
				p[1] = y[i];
				break;
			}
			if(y[i]!=y[i+1]) {
				p[1] = y[i];
				break;
			}
		}
		cout<<p[0]<<" "<<p[1]<<"\n";
	}
	return 0;
}