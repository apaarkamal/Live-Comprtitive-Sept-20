#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int N = 1e6;

int trie[N];

void insert(int x, int node) {
	trie[node]++;
	for (int bit = 17; bit >= 0; bit--) {
		int set = (x >> bit) & 1;
		if (set) {
			node = 2 * node + 2;
			trie[node]++;
		}
		else {
			node = 2 * node + 1;
			trie[node]++;
		}
	}
}

int query(int k, int pref_r, int node) {
	int ans = 0;
	for (int bit = 17; bit >= 0; bit--) {
		int set_k = (k >> bit) & 1;
		int set_r = (pref_r >> bit) & 1;
		if (set_k) {
			if (set_r) {
				ans += trie[2 * node + 2];
				node = 2 * node + 1;
			}
			else {
				ans += trie[2 * node + 1];
				node = 2 * node + 2;
			}
		}
		else {
			if (set_r) {
				node = 2 * node + 2;
			}
			else {
				node = 2 * node + 1;
			}
		}
	}
	return ans;
}

void solve() {
	memset(trie, 0, sizeof(trie));
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int pref_xor = 0, ans = 0;
	insert(pref_xor, 0);
	for (int i = 0; i < n; i++) {
		pref_xor ^= a[i];
		ans += query(k, pref_xor, 0);
		insert(pref_xor, 0);
	}
	cout << ans << '\n';
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

}