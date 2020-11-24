class Solution {
public:
	int longestValidParentheses(string s) {
		int i, n = s.size(), ans = 0, mx = 0;
		if (n == 0) return 0;
		stack<int> St;
		for (i = 0; i < n; i++) {
			if (s[i] == '(') {
				St.push(mx);
				mx = 0;
			}
			else {
				if (St.empty()) {
					mx = 0;
				}
				else {
					mx += St.top() + 2;
					St.pop();
					ans = max(ans, mx);
				}
			}
		}
		return ans;
	}
};



// using dp
class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.empty()) return 0;

		int n = s.size();

		int dp[n] = {};

		for (int i = 1; i < n; i++) {
			if (s[i] == '(') dp[i] = 0;
			else {
				// closing bracket
				if (s[i - 1] == '(') {
					dp[i] = 2 + (i - 2 >= 0 ? dp[i - 2] : 0);
				}
				else {
					if (i - dp[i - 1] - 1 >= 0) {
						if (s[i - dp[i - 1] - 1] == '(') {
							dp[i] = 2 + dp[i - 1] + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
						}
						else {
							dp[i] = 0;
						}
					}
					else {
						dp[i] = 0;
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};