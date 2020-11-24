#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

const int N = 1e5;
vector<int> gr[N], grr[N], comp[N];

vector<int> order;
int vis[N];

void dfs(int cur) {
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (!vis[x]) dfs(x);
	}
	order.push_back(cur);
}

void dfs_rever(int cur, int comp_col) {
	vis[cur] = 1;
	comp[comp_col].push_back(cur);
	for (auto x : grr[cur]) {
		if (!vis[x]) dfs_rever(x, comp_col);
	}
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		grr[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) dfs(i);
	}
	reverse(order.begin(), order.end());
	memset(vis, 0, sizeof(vis));
	int comp_col = 0;
	for (auto x : order) {
		if (!vis[x]) {
			dfs_rever(x, comp_col);
			comp_col++;
		}
	}
	for (int i = 0; i < comp_col; i++) {
		for (auto x : comp[i]) {
			cout << x << " ";
		} cout << '\n';
	}
}