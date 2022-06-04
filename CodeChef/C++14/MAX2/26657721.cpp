#include <iostream>
using namespace std;

int main() {
	int n;
	string x;
	cin>>n;
	cin>>x;
	for(int i=n-1; i>=0; i--) {
	    if(x[i]=='1') {
	        cout<<(n-1-i);
	        break;
	    }
	}
	
	return 0;
}
