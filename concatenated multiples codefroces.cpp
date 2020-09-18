#include<bits/stdc++.h>
#define int long long int
using namespace std;

map<int, int> mp[11];

int len(int x) {
	int ans = 0;
	while (x) {
		x /= 10;
		ans++;
	}
	return ans;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code
	int n , k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[len(a[i])][a[i] % k]++;
	}
	int p10[11];
	p10[0] = 1 % k;
	for (int i = 1; i < 11; i++) {
		p10[i] = p10[i - 1] * 10;
		p10[i] %= k;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int length = 1; length < 11; length++) {
			int val = ((a[i] % k) * (p10[length])) % k;
			int need = (k - val) % k;
			ans += mp[length][need];
		}
	}
	for (int i = 0; i < n; i++) {
		int val = (a[i] * p10[len(a[i])] + a[i]) % k;
		if (val == 0) ans--;
	}
	cout << ans;
}