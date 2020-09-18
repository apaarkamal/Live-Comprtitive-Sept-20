#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

// a^b
int binary_expo(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

// a*b
int binary_multi(int a, int b) {
	int res = 0;
	while (b) {
		if (b & 1) res += a;
		a *= 2;
		b >>= 1;
	}
	return res;
}

// a^b
int binary_expo(int a, int b, int  m) {
	int res = 1;
	while (b) {
		if (b & 1) res *= a, res %= m;

		a *= a;
		a %= m;

		b >>= 1;
	}
	return res;
}

int give_mod(string a, int b) {
	// a%b
	int res = 0;
	for (int i = 0; i < a.size(); i++) {
		res *= 10;
		res += (a[i] - '0');
		res %= b;
	}
	return res;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code
	// cout << binary_expo(2, 5);
	// cout << give_mod("123456", 5);
	cout << binary_multi(2, 8);
}