#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

int gcd(int a, int b) {
	if (a == 0 || b == 0) return a + b;
	return gcd(b % a, a);
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code
	cout << gcd(5, 50);

}