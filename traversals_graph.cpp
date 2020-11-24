#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> gr[N];
int vis[N];

void dfs(int cur) {
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (!vis[x]) dfs(x);
	}
}

// undirected graph cycle detect
bool cycle(int cur, int par) {
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (!vis[x]) {
			if (cycle(x, cur)) return true;
		}
		else if (x != par) {
			// backedge
			return true;
		}
	}
	return false;
}

bool is_cycle = false;
void dfs1(int cur, int par) {
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (!vis[x]) dfs1(x, cur);
		else if (x != par) is_cycle = true;
	}
}

// directed graph cycle detection
bool is_cycle = false;
void dfs_directed(int cur) {
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (vis[x] == 0) dfs_directed(x);
		else if (vis[x] == 1) {
			is_cycle = true;
		}
	}
	vis[cur] = 2;
}

bool is_cycle_bfs(int source, int n) {
	queue<int> Q;
	vector<int> dis(n + 1, 1e8);
	vector<int> par(n + 1);
	Q.push(source);
	dis[source] = 0;
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (auto x : gr[cur]) {
			if (dis[x] == 1e8) {
				dis[x] = 1 + dis[cur];
				Q.push(x);
				par[x] = cur;
			}
			else if (x != par[cur]) {
				// backedge found
				return true;
			}
		}
	}
	return false;
}

void bfs(int source) {
	queue<int> Q;
	Q.push(source);
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (auto x : gr[cur]) {
			if (!vis[x]) {
				vis[x] = 1;
				Q.push(x);
			}
		}
	}
}

int main() {

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
	if (cycle(1, 0)) {
		cout << "cycle";
	}
	else {
		cout << "no cycle";
	}
}