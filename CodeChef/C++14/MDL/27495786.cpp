#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i=a; i<b; i++)

int main() {
	int t, n;
	cin>>t;
	while(t--) {
	    cin>>n;
	    int arr[n], ans[n], pos1, pos2;
	    REP(i, 0, n) {
	        cin>>arr[i];
	        ans[i] = arr[i];
	    }
	    sort(ans, ans+n);
	    
	    REP(i, 0, n) {
	        if(ans[0]==arr[i]) {
	            pos1 = i;
	        }else if(ans[n-1]==arr[i]) {
	            pos2 = i;
	        }
	    }
	    if(pos1<pos2) {
	        cout<<ans[0]<<" "<<ans[n-1]<<"\n";
	    }else {
	        cout<<ans[n-1]<<" "<<ans[0]<<"\n";
	    }
	}
	
	return 0;
}
