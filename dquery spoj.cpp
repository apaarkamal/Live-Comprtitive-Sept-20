#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

struct segmenttree {
	vector<int> st;
	void init(int _n) {
		st.clear();
		st.resize(4 * _n, 0);
	}
	void update(int l, int r, int indup, int val, int node) {
		if (l == r) {
			st[node] = val;
			return;
		}
		else {
			int mid = (l + r) / 2;
			if (indup >= l && indup <= mid) {
				update(l, mid, indup, val, node * 2 + 1);
			}
			else {
				update(mid + 1, r, indup, val, node * 2 + 2);
			}
			st[node] = (st[2 * node + 1] + st[2 * node + 2]);
		}
	}

	int query(int si, int se, int l, int r, int node) {
		if (se < l || si > r || l > r) {
			return 0;
		}
		if (si >= l && se <= r) {
			return st[node];
		}
		int mid = (si + se) / 2;
		int q1 = query(si, mid, l, r, node * 2 + 1);
		int q2 = query(mid + 1, se, l, r, node * 2 + 2);
		return q1 + q2;
	}
};

int previous[1000001];

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	vector<pair<int, int>> queries[n];
	int res[m];
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		l--; r--;
		queries[r].push_back({l, i});
	}
	segmenttree tree;
	tree.init(n);
	memset(previous, -1, sizeof(previous));
	for (int i = 0; i < n; i++) {
		if (previous[a[i]] == -1) {
			// first time
			tree.update(0, n - 1, i, 1, 0);
			previous[a[i]] = i;
		}
		else {
			// remove previousious location of current element
			tree.update(0, n - 1, previous[a[i]], 0, 0);
			// update the latest location
			tree.update(0, n - 1, i, 1, 0);
			previous[a[i]] = i;
		}
		for (auto x : queries[i]) {
			int l = x.first, r = i, index = x.second;
			res[index] = tree.query(0, n - 1, l, r, 0);
		}
	}
	for (int i = 0; i < m; i++) {
		cout << res[i] << " ";
	}
}



