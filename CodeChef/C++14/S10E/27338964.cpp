#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, days;
	bool flag;
	cin>>t;
	while(t--) {
	    cin>>n;
	    int a[n], i;
	    days=0;
	    for(int curr=0; curr<n; curr++) {
	        cin>>a[curr];
	        flag=true;
	        i = ((curr-5)>=0) ? curr-5 : 0;
	        for(i; i<curr; i++) {
	            if(a[i]<=a[curr]) {
	                flag = false;
	                break;
	            }
	        }
	        if(flag) {
	            days++;
	        }
	    }
	    cout<<days<<endl;
	}
	return 0;
}
