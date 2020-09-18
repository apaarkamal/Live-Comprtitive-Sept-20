#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code
	new_data_set St;
	St.insert(4);
	St.insert(5);
	St.insert(2);
	St.insert(8);
	St.insert(10);
	St.insert(12);

	// cout << St.order_of_key(6) << '\n';
	// cout << St.order_of_key(10) << '\n';

	for (int i = 0; i < St.size(); i++) {
		cout << *St.find_by_order(i) << '\n';
	}

}