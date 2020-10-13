#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

struct node {
	node *nxt[2];
	int cnt;
	node() { nxt[0] = nxt[1] = NULL; cnt = 0;}
};

node *root;
void insert(int x) {
	node *cur = root;
	cur->cnt++;
	for (int bit = 20; bit >= 0 ; bit--) {
		int set = ((x >> bit) & 1);
		if (cur->nxt[set] == NULL) {
			cur->nxt[set] = new node();
		}
		cur = cur->nxt[set];
		cur->cnt++;
	}
}

// return an integer x
// such that x^y is maximised
int maximise_xor(int y) {
	node *cur = root;
	int x = 0;
	for (int bit = 20; bit >= 0 ; bit--) {
		int set = (y >> bit) & 1;
		if (cur->nxt[set ^ 1] != NULL) {
			cur = cur->nxt[set ^ 1];
			x += (set ^ 1) * (1 << bit);
		}
		else {
			cur = cur->nxt[set];
			x += set * (1 << bit);
		}
	}
	return x;
}

// numbers less than or equal to x
int less_than_equal_to(int x) {
	node *cur = root;
	int ans = 0;
	for (int bit = 20; bit >= 0 ; bit--) {
		if (cur == NULL) return ans;
		int set = (x >> bit) & 1;
		if (set && cur->nxt[0] != NULL) ans += cur->nxt[0]->cnt;
		cur = cur->nxt[set];
	}
	if (cur != NULL) ans += cur->cnt;
	return ans;
}

int kth_smallest(int k) {
	node *cur = root;
	int x = 0;
	for (int bit = 20; bit >= 0 ; bit--) {
		int set = (x >> bit) & 1;
		if (cur->nxt[0] != NULL && cur->nxt[0]->cnt >= k) {
			// go left
			cur = cur->nxt[0];
		}
		else {
			// go right
			if (cur->nxt[0] != NULL) k -= cur->nxt[0]->cnt;
			cur = cur->nxt[1];
			x += (1 << bit);
		}
	}
	return x;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code
	root = new node();
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		insert(a[i]);
	}
	// int max_xor = 0;
	// for (int i = 0; i < n; i++) {
	// 	max_xor = max(max_xor, (a[i] ^ maximise_xor(a[i])));
	// }
	// cout << max_xor;

	// for (int i = 0; i < n; i++) {
	// 	cout << a[i] << " " << less_than_equal_to(a[i]) << '\n';
	// }
	// cout << less_than_equal_to(8) << '\n';
	for (int i = 1; i <= n; i++) {
		cout << i << " " << kth_smallest(i) << '\n';
	}
}