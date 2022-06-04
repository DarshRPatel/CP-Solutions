#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    int T, i;
    ll a, b, r_a, r_b, sum;
    cin>>T;
    while(T--) {
        cin>>a>>b;
        i=0;
        sum=0;
        while(a || b) {
            r_a = a%10;
            a /= 10;
            r_b = b%10;
            b /= 10;
            sum += ( (r_a+r_b)%10 )*pow(10, i);
            i++;
        }
        cout<<sum<<endl;
    }
    return 0;
}