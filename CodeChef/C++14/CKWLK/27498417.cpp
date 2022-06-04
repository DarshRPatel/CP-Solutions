#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string foo(ll n) {
    ll p1, p2, temp;
    temp = n;
    p1 = p2 = 0;
    while(temp%10==0) {
        p2++;
        temp /= 10;
    }
    while(temp%2==0) {
        p1++;
        temp /= 2;
    }
    if( (pow(2, p1)*pow(10, p2)) == n) {
        if(p1<=p2) {
            return "Yes";
        }
    }
    return "No";
}

int main() {
	ll t, n;
	cin>>t;
	while(t--) {
	    cin>>n;
	    cout<<foo(n)<<"\n";
	}
	
	return 0;
}
