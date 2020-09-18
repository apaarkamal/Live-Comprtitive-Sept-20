#include<bits/stdc++.h>
using namespace std;

bool comp(int x, int y) {
	return x > y;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code

	// string s;
	// getline(cin, s);
	// cout << s;

	// int n;
	// cin >> n;
	// int a[n];
	// for (int i = 0; i < n; i++) {
	// 	cin >> a[i];
	// }
	// int mn = *min_element(a, a + n);
	// int mx = *max_element(a, a + n);
	// int mn = *min_element(a + l, a + r);
	// cout << mn;

	// bubble , insertion, merge, quick, selection
	// sort(a, a + n);

	// int n;
	// cin >> n;
	// int a[n];
	// for (int i = 0; i < n; i++) {
	// 	cin >> a[i];
	// }

	// int index_lb = lower_bound(a, a + n, 3) - a;
	// int index_ub = upper_bound(a, a + n, 3) - a;

	// cout << index_lb << " " << index_ub << '\n';

	// occurences of three
	// cout << upper_bound(a, a + n, 3) - lower_bound(a, a + n, 3);

	// int index_lb = lower_bound(a + 4, a + 8, 3) - a;
	// cout << index_lb << '\n';

	// a   	 a.begin()
	// a+n   a.end()

	// int n;
	// cin >> n;
	// int a[n];
	// for (int i = 0; i < n; i++) {
	// 	cin >> a[i];
	// }
	// O(range)
	// cout << count(a, a + n, 3);

	// sort(a, a + n);
	// reverse(a, a + n);

	// if a was a vector
	// sort(a.rbegin(), a.rend());

	// sort(a, a + n, comp);

	// sort(a, a + n, [&](int x, int y) {
	// 	return x > y;
	// });

	// for (int i = 0; i < n; i++) {
	// 	cout << a[i] << " ";
	// }

	// int n;
	// cin >> n;
	// pair<int, int> a[n];
	// for (int i = 0; i < n; i++) {
	// 	cin >> a[i].first >> a[i].second;
	// }

	// decreasing order of first element
	// increasing order of second element

	// sort(a, a + n, [&](pair<int, int> x, pair<int, int> y) {
	// 	if (x.first == y.first) return x.second < y.second;
	// 	return x.first > y.first;
	// });

	// for (int i = 0; i < n; i++) {
	// 	cout << a[i].first << " " << a[i].second << '\n';
	// }

	// int n;
	// cin >> n;
	// string s[n];
	// sort(s, s + n, [&](string x, string y) {
	// 	return x + y < y + x;
	// });

	// unique
	// int n;
	// cin >> n;
	// int a[n];
	// for (int i = 0; i < n; i++) {
	// 	cin >> a[i];
	// }
	// int i = 0, j = 0, k = 0;
	// while (i < n) {
	// 	j = i;
	// 	while (j < n && a[j] == a[i]) j++;
	// 	a[k] = a[i];
	// 	k++;
	// 	i = j;
	// }
	// n = k;
	// for (int i = 0; i < n; i++) {
	// 	cout << a[i] << " ";
	// }

	// unique() return me an iterator pointing to the
	// last element of the unique

	// sort(a, a + n);
	// n = unique(a, a + n) - a;
	// cout << n;
	// for (int i = 0; i < n; i++) {
	// 	cout << a[i] << " ";
	// }

	// a is a vector

	// a.resize(unique(a.begin(), a.end()) - a.begin());

	// int a[10];
	// iota(a, a + 10, 0);
	// for (int i = 0; i < 10; i++) {
	// 	cout << a[i] << " ";
	// }

	// string s;
	// cin >> s;
	// rotate(s.begin(), s.begin() + 2, s.end());
	// cout << s;

	vector<int> a(5, 10);
	// for (auto x : a) cout << x << " ";
	// vector<int> b = a;
	// vector<int> b(a.begin() + 2, a.end());
	vector<int> b(2, 100);
	// for (auto x : b) a.push_back(x);
	copy(b.begin(), b.end(), back_inserter(a));
	for (auto x : a) cout << x << " ";
}