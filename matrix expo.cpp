#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

const int sz = 2;
const int mod = 1e9 + 7;

struct matrix {
	vector<vector<int>> mat;

	matrix() {
		mat.resize(sz, vector<int>(sz, 0));
	}

	void identity() {
		for (int i = 0; i < sz; i++) {
			mat[i][i] = 1;
		}
	}

	void print_matrix() {
		for (int  i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				cout << mat[i][j] << " ";
			}
			cout << '\n';
		}
	}

	matrix operator* (matrix &b) {
		matrix c;
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				for (int k = 0; k < sz; k++) {
					c.mat[i][j] = (c.mat[i][j] + mat[i][k] * b.mat[k][j]) % mod;
				}
			}
		}
		return c;
	}

};

// fib

int fib(int n) {

	matrix t;
	t.mat = {{1, 1}, {1, 0}};

	matrix res;
	res.identity();
	n--;

	while (n) {
		if (n & 1) res = res * t;
		t = t * t;
		n /= 2;
	}

	// res.print_matrix();
	int ans = res.mat[0][0] * 1 + res.mat[0][1] * 0;

	return ans;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code
	cout << fib(6);
}


