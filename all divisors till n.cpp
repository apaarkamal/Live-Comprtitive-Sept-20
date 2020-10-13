#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

const int N = 1e5;

vector<int> divisors(N, 0);

void seive() {
	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j += i) {
			divisors[j]++;
		}
	}
	return;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code

	seive();

	int n;
	cin >> n;

	// divisors isors of this n
	// cout << divisors[n];

	for (int i = 0; i < 100; i++) {
		cout << i << " " << divisors[i] << '\n';
	}

}