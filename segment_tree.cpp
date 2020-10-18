#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

struct segment_tree {
	vector<int> st;
	void init(int n) {
		st.resize(4 * n, 0);
	}
	void build(int a[], int start, int end, int node) {
		if (start == end) {
			st[node] = a[start];
			return ;
		}
		int mid = (start + end) / 2;
		build(a, start, mid, 2 * node + 1);
		build(a, mid + 1, end, 2 * node + 2);
		st[node] = st[2 * node + 1] + st[2 * node + 2];
	}
	void update(int start, int end, int index, int val, int node) {
		if (start == end) {
			// start == end == index
			st[node] = val;
			return;
		}
		int mid = (start + end) / 2;
		if (index <= mid) {
			update(start, mid, index, val, 2 * node + 1);
		}
		else {
			update(mid + 1, end, index, val, 2 * node + 2);
		}
		st[node] = st[2 * node + 1] + st[2 * node + 2];
	}
	int query(int start, int end, int l, int r, int node) {
		// no overlap
		if (start > r || end < l) return 0;
		// complete overlap
		if (l <= start && end <= r) return st[node];
		// partial overlap
		int mid = (start + end) / 2;
		int q1 = query(start, mid, l, r, 2 * node + 1);
		int q2 = query(mid + 1, end, l, r, 2 * node + 2);
		return q1 + q2;
	}
};

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
	segment_tree tree;
	tree.init(n);
	tree.build(a, 0, n - 1, 0);
	// on index 3 update 5
	tree.update(0, n - 1, 3, 5, 0);
	cout << tree.query(0, n - 1, 1, 3, 0);
}