#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

vector<int> give_div(int n) {
	vector<int> div;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			div.push_back(i);
			if (i != n / i) {
				div.push_back(n / i);
			}
		}
	}
	sort(div.begin(), div.end());
	return div;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code
	int n;
	cin >> n;
	vector<int> div = give_div(n);
	for (auto x : div) cout << x << " ";
}