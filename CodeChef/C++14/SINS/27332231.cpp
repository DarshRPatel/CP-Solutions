#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll T, x, y, sum;
	cin>>T;
	while(T--) {
	    cin>>x>>y;
	    if(x==y || x==0 || y==0) {
	        cout<<x+y<<endl;
	        continue;
	    }
	    sum = __gcd(x, y) * 2;
	    cout<<sum<<endl;
	}
	
	return 0;
}
