#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

// O(sqrt(n))
vector<pair<int, int>> factorisation(int n) {
	vector<pair<int, int>> res;
	int cnt = 0;
	while (n % 2 == 0) {
		cnt++;
		n /= 2;
	}
	if (cnt) res.push_back({2, cnt});
	// now n has t be a odd number

	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			// claim : i has to be prime
			cnt = 0;
			while (n % i == 0) {
				n /= i;
				cnt++;
			}
			res.push_back({i, cnt});
		}
	}

	if (n > 1) res.push_back({n, 1});

	return res;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code
	int n;
	cin >> n;
	vector<pair<int, int>> prime_factor = factorisation(n);

	for (auto x : prime_factor) {
		cout << x.F << " " << x.S << '\n';
	}

}