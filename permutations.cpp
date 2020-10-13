#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

void permute(int cur, string s) {
	if (cur == s.size()) {
		cout << s << '\n';
		return ;
	}
	for (int i = cur; i < s.size(); i++) {
		swap(s[cur], s[i]);
		permute(cur + 1, s);
		swap(s[cur], s[i]);
	}
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code
	string s = "abcd";
	permute(0, s);
}