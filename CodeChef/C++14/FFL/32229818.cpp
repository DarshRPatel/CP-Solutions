#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n ,s, base, baseP;
    bool flag;
    cin>>t;
    while(t--) {
        flag = false;
        cin>>n>>s;
        s = 100 - s;
        int arr[2][n];
        for(int i=0; i<2; i++) {
            for(int j=0; j<n; j++) {
                cin>>arr[i][j];
            }
        }
        for(int i=0; i<n; i++) {
            if(arr[1][i] == 0) {
                base = arr[1][i];
                baseP = arr[0][i];

                for(int j=0; j<n; j++) {
                    if( (base!=arr[1][j]) && (baseP+arr[0][j] <= s) ) {
                        flag = true;
                        break;
                    }
                }
            }
            if(flag) {
                break;
            }
        }
        if(flag) {
            cout<<"yes"<<endl;
        }else {
            cout<<"no"<<endl;
        }
    }

    return 0;
}