#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

vector<int> subsetsum(vector<int> a) {
	vector<int> res;
	int n = a.size();
	for (int i = 0; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) sum += a[j];
		}
		res.push_back(sum);
	}
	return res;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> left(n / 2), right(n - n / 2);
	for (int i = 0; i < n; i++) {
		if (i < n / 2) left[i] = a[i];
		else right[i - n / 2] = a[i];
	}

	vector<int> left_sum = subsetsum(left);
	vector<int> right_sum = subsetsum(right);

	sort(right_sum.begin(), right_sum.end());

	for (auto x : left_sum) {
		int y = k - x;
		// x+y = k
		if (binary_search(right_sum.begin(), right_sum.end(), y)) {
			cout << "Yes subset exist";
			return 0;
		}
	}

	cout << "NO , not exist";

}