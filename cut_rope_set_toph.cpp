#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long int
#define F first
#define S second

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code

	int t, z = 1;
	cin >> t;
	while (t--) {
		cout << "Case " << z++ << ":\n";

		int n, q, temp = 0;
		cin >> n >> q;

		set<pair<int, int>> St;
		new_data_set PBDS;

		St.insert({1, n});
		PBDS.insert({n, temp++});

		while (q--) {

			char ch;
			int x;
			cin >> ch >> x;

			if (ch == 'F') {
				// find
				cout << PBDS.find_by_order(x - 1)->first << '\n';
			}
			else {
				// cut
				auto it = St.lower_bound({x, x});
				it--;

				int l = it->first, r = it->second;
				int e_length = r - l + 1;

				auto it1 = PBDS.lower_bound({e_length, 0});
				PBDS.erase(it1);

				St.erase(it);

				St.insert({l, x});
				PBDS.insert({x - l + 1, temp++});

				St.insert({x + 1, r});
				PBDS.insert({r - (x + 1) + 1, temp++});


			}

		}

	}

}