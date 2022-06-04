#include <iostream>
using namespace std;

long long int gcd(long long int a, long long int b) { 
    if (a == 0 || b == 0) { 
        return 0;
    }else if (a == b) {
        return a; 
    }else if (a > b) { 
        if(a%b==0) {
            return b;
        }
        return gcd(b, a%b);
    }else {
        if(b%a==0) {
            return a;
        }
        return gcd(b%a, a);
    }
}

int main() {
	long long int t, a, b, gc, lcm;
	cin>>t;
	while(t--) {
	    cin>>a>>b;
	    gc = gcd(a, b);
	    if(gcd==0) {
	        lcm=0;
	    }else {
	        lcm = (a*b)/gc;
	    }
	    cout<<gc<<" "<<lcm<<endl;
	}
	return 0;
}
