#include <iostream>
using namespace std;

int main() {
	int t, n, a, b, temp, f_a, f_b;
	double prob_win;
	cin>>t;
	for(int i=0; i<t; i++) {
	    f_a=0;
	    f_b=0;
	    cin>>n>>a>>b;
	    for(int j=0; j<n; j++) {
	        cin>>temp;
	        if(temp==a) f_a++;
	        if(temp==b) f_b++;
	    }
	    prob_win = (double)(f_a*f_b)/(n*n);
	    printf("%f\n", prob_win);
	}
	
	return 0;
}
