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
#define MAX						100

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
		vl a(n);
		ll c[7] = {0};
		bool flag = true;
		rep(i, n) {
			cin>>a[i];
			if(a[i]>7) flag = false;
			else c[a[i]-1] += 1;
		}
		if(!flag) cout<<"no\n";
		else if(a[0]!=1 || a[n-1]!=1) cout<<"no\n";
		else {
			rep(i, 7) {
				if(c[i]==0) {
					flag = false;
					break;
				}
			}
			if(flag) {
				ll i=0, j=n-1, cnt=0, num=1;
				while(i<=j) {
					while(a[i]==num) {
						i++;
						cnt++;
					}
					if(cnt==0) {
						flag = false;
						break;
					}
					while(a[j]==num) {
						j--;
						cnt--;
					}
					if(cnt!=0) {
						flag = false;
						break;
					}
					num++;
				}
				if(flag) cout<<"yes\n";
				else cout<<"no\n";	
			}else cout<<"no\n";	
		}
	}
	return 0;
}