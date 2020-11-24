#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		int dx = 0, dy = 0;
		stack<pair<int, int>> St;
		stack<int> St1;
		// (0,0) initially
		for (int i = 0; i < n; i++) {
			if (s[i] == '(') {
				// whenever a opening bracket
				// we have s[i-1] to be the integer
				St1.push(s[i - 1] - '0');
				St.push({dx, dy});
				dx = 0; dy = 0;
			}
			else if (s[i] == ')') {
				dx *= St1.top();
				dy *= St1.top();
				St1.pop();
				dx += St.top().first;
				dy += St.top().second;
				St.pop();
			}
			else {
				// integer or a direction
				if (s[i] == 'N') dy--;
				else if (s[i] == 'S') dy++;
				else if (s[i] == 'E') dx++;
				else if (s[i] == 'W') dx--;
			}
			dx %= 1000000000;
			dy %= 1000000000;
			dx += 1000000000;
			dy += 1000000000;
			dx %= 1000000000;
			dy %= 1000000000;
		}
		cout << dx + 1 << " " << dy + 1 << '\n';
	}
}