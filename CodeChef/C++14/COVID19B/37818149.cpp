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

int main() {
	doublade();
	w(t) {
		ll n;
		cin >> n;
		vl a(n);
		rep(i, n) {
			cin>>a[i];
		}
		vl arr(n);
		if(n==1) arr[0] = 1;
		else {
			rep(i, n) {
				ll tmp =  1;
				if(i==0) {
					f(j, i+1, n) if(a[i]>a[j]) tmp++;
				}else if(i==n-1) {
					rep(j, n-1) if(a[j]>a[i]) tmp++;
				}else {
					vl infec(n, 0);
					infec[i] = 1;
					ll minI = a[i], maxI = a[i];
					f(j, i+1, n) {
						if(a[i]>a[j]) {
							infec[j] = 1;
							minI = min(minI, a[j]);
						}
					}
					rep(j, i) {
						if(a[j]>a[i]) {
							infec[j] = 1;
							maxI = max(maxI, a[j]);
						}
					}
					rep(j, i) if(!infec[j] && a[j]>minI) infec[j]=1;
					f(j, i+1, n) if(!infec[j] && maxI>a[j]) infec[j]=1;
					
					tmp = 0;
					rep(i, n) if(infec[i]) tmp++;
				}
				arr[i] = tmp;
			}
		}
		// for(auto x:arr) cout<<x<<" ";
		// cout<<"\n";
		sort(all(arr));
		cout<<arr[0]<<" "<<arr[n-1]<<"\n";
	}
	return 0;
}