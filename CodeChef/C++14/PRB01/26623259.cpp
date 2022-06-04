#include <iostream>
#include <cmath>
using namespace std;

int isPrime(int a) {
    if(a==1 || a==2) {
        return 1;
    }else {
        for(int i=2; i<=ceil(sqrt(a)); i++) {
            if(a%i==0) {
                if(i!=a) {
                    return 0;
                }
            }
        }
        return 1;
    }
}

int main() {
	int t, num;
	cin>>t;
	for(int i=0; i<t; i++) {
	    cin>>num;
        if(isPrime(num)) {
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
	}
	
	return 0;
}
