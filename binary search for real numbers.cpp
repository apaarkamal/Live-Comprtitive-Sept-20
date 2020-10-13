#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

double check(double x) {
	double ans = 7;
	ans *= x;
	ans -= 22;
	return ans;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code

	double lf = 1, rt = 10;

	while (rt - lf >= 0.00000000001) {
		double mid = (lf + rt) / 2.00;
		if (check(lf)*check(mid) > 0.00) {
			lf = mid;
		}
		else {
			rt = mid;
		}
	}
	cout << setprecision(20) << fixed;
	cout << lf << " " << rt << '\n';

}