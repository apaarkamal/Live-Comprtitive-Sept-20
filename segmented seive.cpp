#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

const int N = 1e5;

int pr[N];
vector<int> primes;

void seive() {
	int i, j;
	for (i = 2; i < N; i++) {
		if (!pr[i]) {
			primes.push_back(i);
			for (j = i; j < N; j += i) {
				pr[j]++;
			}
		}
	}
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code

	seive();

	int t;
	cin >> t;
	while (t--) {

		int m, n;
		cin >> m >> n;

		vector<bool> ss(n - m + 1, true);

		for (auto prime : primes) {
			// we need primes till sqrt(n)
			if (prime * prime > n) break;
			// now all prime are less than sqrt(n)
			int start = (m / prime) * prime;

			// if prime lies in my given range
			if (prime >= m) start = prime * 2;
			// cancel out multiles off prime in the
			// given segment
			for (int i = start; i <= n; i += prime) {
				if (i >= m) {
					ss[i - m] = 0;
				}
			}

		}

		for (int i = m; i <= n; i++) {
			if (ss[i - m] == true && i != 1) {
				// i is a prime
				cout << i << '\n';
			}
		}
		cout << '\n';
	}




}