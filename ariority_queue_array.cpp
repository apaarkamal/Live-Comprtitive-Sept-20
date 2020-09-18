#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code
	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;
		priority_queue<vector<int>> Q;

		// {length,starting,ending}
		Q.push({n, 0, n - 1});
		int res[n], val = 1;

		while (!Q.empty()) {

			vector<int> temp = Q.top();
			Q.pop();
			int length = temp[0];
			int starting = -temp[1];
			int ending = temp[2];

			int mid = (starting + ending) / 2;
			res[mid] = val++;

			if (starting <= mid - 1) {
				Q.push({(mid - 1) - starting + 1, -starting, mid - 1});
			}
			if (mid + 1 <= ending) {
				Q.push({(ending) - (mid + 1) + 1, -(mid + 1), ending});
			}

		}

		for (int i = 0; i < n; i++) {
			cout << res[i] << " ";
		}
		cout << '\n';

	}
}