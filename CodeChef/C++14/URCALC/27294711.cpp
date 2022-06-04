#include <iostream>
using namespace std;

int main() {
	double a, b, ans;
	string oper;
	cin>>a>>b;
	cin>>oper;
	if(oper=="+") {
	    ans = a+b;
	}else if(oper=="-") {
	    ans = a-b;
	}else if(oper=="*") {
	    ans = a*b;
	}else if(oper=="/") {
	    ans = a/b;
	}
	printf("%.6lf", ans);
	
	return 0;
}
