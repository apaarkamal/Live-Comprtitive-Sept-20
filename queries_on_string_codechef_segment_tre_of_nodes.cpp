#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

const int N = 1e3 + 2;
string s;

struct node {
	int pref[3];
	int sum;
	node() {
		memset(pref, 0, sizeof(pref));
		sum = 0;
	}
} st[N * 4 + 1];

struct segment_tree {
	void merge_nodes(node &cur, node &left, node &right) {
		if (left.sum == 0) {
			cur.pref[0] = left.pref[0] + right.pref[0];
			cur.pref[1] = left.pref[1] + right.pref[1];
			cur.pref[2] = left.pref[2] + right.pref[2];
		}
		else if (left.sum == 1) {
			cur.pref[0] = left.pref[0] + right.pref[2];
			cur.pref[1] = left.pref[1] + right.pref[0];
			cur.pref[2] = left.pref[2] + right.pref[1];
		}
		else {
			cur.pref[0] = left.pref[0] + right.pref[1];
			cur.pref[1] = left.pref[1] + right.pref[2];
			cur.pref[2] = left.pref[2] + right.pref[0];
		}
		cur.sum = (left.sum + right.sum) % 3;
	}
	void build(int start, int end, int node) {
		if (start == end) {
			st[node].pref[(s[start] - '0') % 3]++;
			st[node].sum = (s[start] - '0') % 3;
			return ;
		}
		int mid = (start + end) / 2;
		build(start, mid, 2 * node + 1);
		build(mid + 1, end, 2 * node + 2);
		// merge left and right
		merge_nodes(st[node], st[2 * node + 1], st[2 * node + 2]);
	}
	void update(int start, int end, int index, int val, int node) {
		if (start == end) {
			st[node].pref[0] = st[node].pref[1] = st[node].pref[2] = 0;
			st[node].pref[val % 3]++;
			st[node].sum = val % 3;
			return;
		}
		int mid = (start + end) / 2;
		if (index <= mid) {
			update(start, mid, index, val, 2 * node + 1);
		}
		else {
			update(mid + 1, end, index, val, 2 * node + 2);
		}
		merge_nodes(st[node], st[2 * node + 1], st[2 * node + 2]);
	}
	node query(int start, int end, int l, int r, int cur_node) {
		if (start > r || end < l) {
			node temp;
			return temp;
		}
		if (start >= l && end <= r) {
			return st[cur_node];
		}
		int mid = (start + end) / 2;
		node res1 = query(start, mid, l, r, 2 * cur_node + 1);
		node res2 = query(mid + 1, end, l, r, 2 * cur_node + 2);
		node res;
		merge_nodes(res, res1, res2);
		return res;
	}
};

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code
	int n, m;
	cin >> n >> m;
	cin >> s;
	segment_tree tree;
	tree.build(0, n - 1, 0);
	while (m--) {
		int type, l, r;
		cin >> type >> l >> r;
		if (type == 1) {
			l--;
			tree.update(0, n - 1, l, r, 0);
		}
		else {
			l--; r--;
			node res = tree.query(0, n - 1, l, r, 0);
			// cout << res.pref[0] << " " << res.pref[1] << " " << res.pref[2] << " " << res.sum << '\n';
			int ans = (res.pref[0] * (res.pref[0] + 1)) / 2;
			ans += (res.pref[1] * (res.pref[1] - 1)) / 2;
			ans += (res.pref[2] * (res.pref[2] - 1)) / 2;
			cout << ans << '\n';
		}
	}
}