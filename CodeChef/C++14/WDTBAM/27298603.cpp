#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int T;
    cin>>T;
    while(T--) {
        ll n, c=0, max=0;
        cin>>n;
        string s1, s2;
        cin>>s1>>s2;
        for(ll i=0; i<n; i++) {
            if(s1[i]==s2[i]) {
                c++;
            }
        }
        ll a[n+1];
        for(ll i=0; i<n+1; i++) {
            cin>>a[i];
            if(i<=c && max<a[i]) {
                max = a[i];
            }
        }
        if(c==n) {
            max=a[n]; 
        }
        cout<<max<<endl;
    }
    
    return 0;
}