#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

const int N = 1e5;

vector<int> prime;
vector<bool> p;

void seive() {
	p.resize(N, true);
	p[0] = p[1] = 0;

	for (int i = 2; i * i < N; i++) {
		if (p[i] == true) {
			// i is a prime number
			prime.push_back(i);
			for (int j = i * i; j < N; j += i) {
				p[j] = false;
			}
		}
	}
	// for (int i = 0; i < 20; i++) {
	// 	cout << i << " " << p[i] << '\n';
	// }
	return;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code

	seive();

	// for (auto x : prime) cout << x << '\n';

	int n;
	cin >> n;

	if (binary_search(prime.begin(), prime.end(), n)) {
		cout << "prime";
	}
	else {
		cout << "not prime";
	}


}