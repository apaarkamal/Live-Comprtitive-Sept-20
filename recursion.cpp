#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

vector<pair<int, int>> pf;

void fun(int cur, int ans) {

	if (cur == pf.size()) {
		cout << ans << '\n';
		return;
	}

	int prime = pf[cur].first;
	int q = pf[cur].second;

	for (int i = 0; i <= q; i++) {
		fun(cur + 1, ans * pow(prime, i));
	}

}

void print_sub(int cur, string s, string res) {
	// s[cur]
	if (cur == s.size()) {
		cout << res << '\n';
		return;
	}
	// include in sub
	print_sub(cur + 1, s, res + s[cur]);
	// exclude
	print_sub(cur + 1, s, res);
}

bool is_palindrome(string s, int l, int r) {
	if (l == r) return true; // odd length
	if (l == r - 1) return (s[l] == s[r]); // even length
	return is_palindrome(s, l + 1, r - 1) && (s[l] == s[r]);
}

string keypad[10] = {" ", ".,?!" , "abc", "def", "ghi", "jkl",
                     "mno", "pqrs", "tuv", "wxyz"
                    };

void nokia(int cur, string s, string res) {
	if (cur == s.size()) {
		cout << res << '\n';
		return;
	}
	for (auto x : keypad[s[cur] - '0']) {
		nokia(cur + 1, s, res + x);
	}
}

int knapsack(int cur, int value[], int weight[], int w, int n) {
	if (cur == n) return 0;

	// w and n memoise
	// dp programming problem

	int max_profit = 0;

	// exclude
	max_profit = max(max_profit, knapsack(cur + 1, value, weight, w, n));

	// include
	if (weight[cur] <= w) {
		max_profit = max(max_profit, value[cur] +
		                 knapsack(cur + 1, value, weight, w - weight[cur], n));
	}
	return max_profit;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code
	// pf.push_back({2, 3});
	// pf.push_back({5, 1});
	// pf.push_back({3, 4});
	// fun(0, 1);

	// string s = "abcd";
	// print_sub(0, s, "");

	// is_palindrome("aba", 0, 2);

	// nokia keypad
	// nokia(0, "234", "");

	// knapsack
	int value[3] = {60, 100, 120};
	int weight[3] = {10, 20, 30};
	int w = 50;
	cout << knapsack(0, value, weight, w, 3);

}