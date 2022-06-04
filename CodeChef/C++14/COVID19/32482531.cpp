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
#define f(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) f(i,0,n)

int main()
{
    int t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        int arr[n], n1, n2, temp;
        n1 = 0;n2 = 0;temp = 1;
        rep(i, n) {
            cin>>arr[i];
        }

        f(i, 1, n) {
            if(arr[i] - arr[i-1] <= 2) {
                temp++;
            }else {
                n1 = max(n1, temp);
                n2 = (n2==0) ? n1 : min(n2,temp);
                temp = 1;
            }

        }

        n1 = max(n1, temp);
        n2 = (n2==0) ? n1 : min(n2, temp);

        cout<<n2<<" "<<n1<<endl;

    }

    return 0;
}
