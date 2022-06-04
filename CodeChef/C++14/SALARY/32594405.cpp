#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define ll long long int
#define f(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) f(i,0,n)

void foo(ll *w, ll n, ll pos, ll t) {
    rep(i, n) {
        w[i] += (i!=pos) ? t : 0;
    }
}

int main()
{
    ll t, n, ans;
    cin>>t;
    while(t--) {
        cin>>n;
        ll w[n];
        ans = 0;
        rep(i, n) {
            cin>>w[i];
        }
        sort(w, w+n);
        f(i, 1, n) {
            if(w[i]>w[i-1]) {
                ll t = w[i] - w[i-1];
                foo(w, n, i, t);
                ans += t;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
