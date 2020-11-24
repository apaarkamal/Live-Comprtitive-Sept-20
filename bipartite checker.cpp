#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

const int N = 1e5;
vector<int> gr[N];

bool odd_cycle = 0;

int vis[N];

void dfs(int cur, int col) {
	vis[cur] = col;
	for (auto x : gr[cur]) {
		if (vis[x] == 0) dfs(cur, 3 ^ col);
		else if (vis[x] == col) {
			odd_cycle = true;
		}
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
		gr[y].push_back(x);
	}
	dfs(1, 1);
	if (odd_cycle) {
		cout << "not bipartite";
	}
	else {
		cout << "bipartite";
	}
}


