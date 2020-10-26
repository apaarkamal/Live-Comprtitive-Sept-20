#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

const int N = 400005;
int index[N];

struct fenwick {
	vector<int> fn;
	int n;
	void init(int _n) {
		n = _n + 10;
		fn.clear(); fn.resize(n, 0);
	}
	void add(int x, int val) {
		x++;// 1 based indexing
		while (x < n) {
			fn[x] += val;
			x += (x & (-x));
		}
	}
	int sum(int x) {
		x++;//1 basaed indexing
		int ans = 0;
		while (x) {
			ans += fn[x];
			x -= (x & (-x));
		}
		return ans;
	}
	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
} bit;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code

	int n;
	cin >> n;
	int l[n], r[n];
	vector<int> temp;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		temp.push_back(l[i]);
		temp.push_back(r[i]);
	}
	sort(temp.begin(), temp.end());
	memset(index, -1, sizeof(index));
	for (int i = 0; i < n; i++) {
		// cordinate compression
		l[i] = (lower_bound(temp.begin(), temp.end(), l[i]) - temp.begin()) + 1;
		r[i] = (lower_bound(temp.begin(), temp.end(), r[i]) - temp.begin()) + 1;
		index[r[i]] = i;
	}
	int res[n];
	bit.init(N);
	for (int i = 1; i < N; i++) {
		if (index[i] == -1) continue;
		// index[i] is the index of the range that ended at r
		res[index[i]] = bit.sum(l[index[i]], r[index[i]]);
		bit.add(l[index[i]], 1);
	}

	for (int i = 0; i < n; i++) {
		cout << res[i] << '\n';
	}



}