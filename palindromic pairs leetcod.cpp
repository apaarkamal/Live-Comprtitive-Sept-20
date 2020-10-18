#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define vi vector<int>

const int N = 100005;

class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string> words) {
		vector<vector<int>> res;
		map<string, int> mp;
		for (int i = 0; i < words.size(); i++) {
			mp[words[i]] = i;
		}
		for (int i = 0; i < words.size(); i++) {
			string pref = "";
			for (int j = 0; j < words[i].size(); j++) {
				reverse(pref.begin(), pref.end());
				if (palindrome(words[i].substr(j))) {
					if (mp.count(pref)) {
						res.push_back({i, mp[pref]});
					}
				}
				reverse(pref.begin(), pref.end());
				pref += words[i][j];
			}
		}
		for (int i = 0; i < words.size(); i++) {
			string suffix = "";
			for (int j = words[i].size() - 1; j >= 0 ; j--) {
				reverse(suffix.begin(), suffix.end());
				if (palindrome(words[i].substr(0, j + 1))) {
					if (mp.count(suffix)) {
						res.push_back({ mp[suffix], i});
					}
				}
				reverse(suffix.begin(), suffix.end());
				suffix = words[i][j] + suffix;
			}
		}
		for (int i = 0; i < words.size(); i++) {
			string rev = words[i];
			reverse(rev.begin(), rev.end());
			if (mp.count(rev) && rev != words[i]) {
				res.push_back({i, mp[rev]});
			}
		}
		return res;
	}
	bool palindrome(string s) {
		int i = 0, j = s.size() - 1;
		while (i <= j) {
			if (s[i] != s[j]) return false;
			i++; j--;
		}
		return true;
	}
};

int32_t main() {

	// string s, t;
	// cin >> s >> t;

	// string s;
	// cin >> s;

	// int n; cin >> n;
	// vector<int> a(n);
	// for (int i = 0; i < n; i++) cin >> a[i];

	Solution H;
	vector<vector<int>> temp = H.palindromePairs({"abcd", "dcba", "lls", "s", "sssll"});
	for (auto x : temp) {
		cout << x[0] << " " << x[1] << '\n';
	}

}