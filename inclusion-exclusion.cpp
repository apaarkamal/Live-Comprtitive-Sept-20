#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code

	int n;
	cin >> n;

	vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
	int m = 8;
	int ans = 0;

	for (int mask = 1; mask < (1 << m); mask++) {
		int lcm = 1;
		for (int bit = 0; bit < m; bit++) {
			if ((mask >> bit) & 1) {
				lcm *= primes[bit];
			}
		}

		if (__builtin_popcount(mask) % 2 == 1) {
			ans += n / lcm;
		}
		else {
			ans -= n / lcm;
		}
		// cout << lcm << '\n';
	}

	cout << ans;

}