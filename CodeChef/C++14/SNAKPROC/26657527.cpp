#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
	int r, l, flag;
	string s;
	cin>>r;
	
	for(int i=0; i<r; i++) {
	    s="";
	    flag=0;
	    cin>>l;
	    getchar();
	    getline(cin, s, '\n');
	    for(int j=0; j<l; j++) {
	        if(s[j]=='.') {
	        }else if((flag==0 && s[j]!='H')||(flag==1 && s[j]!='T')) {
	            cout<<"Invalid"<<endl;
	            break;
	        }else if((s[j]=='H' && flag==0)||(s[j]=='T' && flag==1)) {
	            flag = flag ? 0 : 1;
	        }
	        
	        if(j==l-1) {
	            if(flag==0) {
	                cout<<"Valid"<<endl;
	            }else {
                    cout<<"Invalid"<<endl;
	            }
	        }
	    }
	}
	
	return 0;
}
