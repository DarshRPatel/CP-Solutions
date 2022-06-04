#include<bits/stdc++.h>

#define LIMIT 9

using namespace std;

void arr_maker(long long a, long long *arr) {
    long long temp;
    for(int i=0; i<=LIMIT; i++) {
        temp = a%10;
        arr[i] = temp;
        a = (a-temp)/10;
    }
}

void calc(long long *arr1, long long *arr2, long long *arr3) {
    for(int i=0; i<=LIMIT; i++) {
        arr3[i] = (arr1[i] + arr2[i])%10;
    }
}

long long arr_to_num(long long *arr) {
    long long sum = 0;
    for(int i=0; i<=LIMIT; i++) {
        sum+=arr[i] * pow(10, i);
    }
    return sum;
}

int main() {
	int T;
	long long a, b, sum[LIMIT] = {0}, arr_a[LIMIT] = {0}, arr_b[LIMIT] = {0};
	cin>>T;
	while(T--) {
	    cin>>a>>b;
	    arr_maker(a, arr_a);
	    arr_maker(b, arr_b);
	    calc(arr_a, arr_b, sum);
	    cout<<arr_to_num(sum)<<endl;
	}
	return 0;
}
