#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<long long> vl;
typedef pair<long long, long long> pl;
typedef vector<vector<long long>> matrix;

#define F 						first
#define S 						second
#define PB 						push_back
#define MP 						make_pair
#define all(c) 					c.begin(), c.end()
#define f(i,a,b) 				for(ll i=a; i<b; i++)
#define rep(i,n) 				f(i,0,n)
#define tr(c,i) 				for(typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define present(c,x) 			(c.find(x) != c.end())	//for set and map
#define cpresent(c,x) 			(find(all(c),x) != c.end())	//for vectors
#define w(t)					ll t; cin>>t; while(t--)
#define epsilon 				1e-9
#define MOD						(ll)1e9

void doublade() {
	ios::sync_with_stdio(false); cin.tie(0); cout.precision(10);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

ll prec(char c) {
	if(c=='^') return 3;
	else if(c=='*' || c=='/') return 2;
	else if(c=='+' || c=='-') return 1;
	else return -1;
}

void infixToPostfix(string s, ll n) {
	string ans = "";
	stack<char> st;
	st.push('N');
	rep(i, n) {
		if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) ans += s[i];
		else if(s[i]=='(') st.push(s[i]);
		else if(s[i]==')') {
			while(st.top()!='N' && st.top()!='(') {
				ans += st.top();
				st.pop();
			}
			if(st.top()=='(') st.pop();
		}else {
			while(st.top()!='N' && prec(s[i]) <= prec(st.top())) {
				ans += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while(st.top()!='N') {
		ans += st.top();
		st.pop();
	}
	cout<<ans<<"\n";
}

int main() {
	doublade();
	w(t) {
		ll n;
		string s;
		cin >> n >> s;
		infixToPostfix(s, n);
	}

	return 0;

}