#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

const int N = 8;

int grid[N][N];

void print_grid() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << (grid[i][j] ? "Q" : ".");
		} cout << '\n';
	}
	cout << '\n';
}

bool check(int row, int col) {
	int i = row, j = col;

	// vertical check
	while (i >= 0) {
		if (grid[i][j] == 1) return false;
		i--;
	}

	// left diagonal
	i = row, j = col;
	while (i >= 0 && j >= 0) {
		if (grid[i][j] == 1) return false;
		i--; j--;
	}

	// right diagonal
	i = row, j = col;
	while (i >= 0 && j < N) {
		if (grid[i][j] == 1) return false;
		i--; j++;
	}

	return true;
}

int cnt;

void nqueen(int row) {

	if (row == N) {
		print_grid();
		cnt++;
		exit(0);
		return;
	}

	for (int col = 0; col < N; col++) {
		if (check(row, col)) {
			// place the queen
			grid[row][col] = 1;
			// recur for the next row
			nqueen(row + 1);
			// backtrack
			grid[row][col] = 0;
		}
	}

}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code
	nqueen(0);
}