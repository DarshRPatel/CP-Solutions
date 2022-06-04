#include <iostream>
#include <cmath>
using namespace std;

int main() {

	int t, n;
	bool flag;
	long int sum;
	cin>>t;
	while(t--) {
        cin>>n;
        sum = 0;
        flag=false;
        long int arr[n];
        for(int j=0; j<n; j++) {
            cin>>arr[j];
            sum += arr[j];
        }
        for(int j=0; j<n; j++) {
            if(sum == n*arr[j]) {
                cout<<j+1<<endl;
                flag = true;
                break;
            }
        }
        if(!flag) {
            cout<<"Impossible"<<endl;
        }
	}

	return 0;
}