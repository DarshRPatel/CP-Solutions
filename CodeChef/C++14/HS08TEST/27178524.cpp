#include <iostream>
using namespace std;

int main() {
	int x;
	double y;
    cin>>x>>y;
    if( (x%5==0) && (y>=(x+.5)) ) {
        y -= x+.5;
    }
    printf("%.2lf", y);
    
	return 0;
}
