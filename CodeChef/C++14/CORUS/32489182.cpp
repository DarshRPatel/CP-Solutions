#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;
#define ll long long int
#define f(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) f(i,0,n)

int main()
{
    ll t, n, q, temp, penQue;
    string s;
    cin>>t;
    while(t--) {
        cin>>n>>q;
        ll c[q];
        ll arr[26] = {0};
        cin>>s; //size of s = n
        rep(i, n) {
            arr[int(s[i])-97]++;
        }
        rep(i, q) {
            penQue = 0;
            temp = 0;
            cin>>c[i];
            rep(j, 26) {
                temp += (arr[j]>=c[i]) ? c[i] : arr[j];
            }
            penQue = n - temp;
            cout<<penQue<<endl;
        }
    }

    return 0;
}
