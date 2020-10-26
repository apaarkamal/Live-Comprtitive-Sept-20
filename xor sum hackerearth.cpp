#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int N = 1e5 + 5, M = 42;

int pref[N][M];
int a[N];

const int mod = 1000000007;
int fact[N], invfact[N];
inline int add(int x, int y) { x += y; return x % mod;}
inline int sub(int x, int y) { x -= y; x %= mod; x += mod; return x % mod;}
inline int mul(int x, int y) { return  (x * y) % mod;}
inline int powr(int a, int b) {
	int x = 1 % mod;
	b %= (mod - 1);
	while (b) {
		if (b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a) { return powr(a, mod - 2);}
void pre() {
	fact[0] = invfact[0] = 1;
	for (int i = 1; i < N; i++) fact[i] = mul(i, fact[i - 1]);
	invfact[N - 1] = inv(fact[N - 1]);
	for (int i = N - 2; i >= 1; i--) invfact[i] = mul(invfact[i + 1], i + 1);
	assert(invfact[1] == 1);
}

inline int C(int n, int k) {
	if (n < k || k < 0) return 0;
	return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code
	pre();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < M; j++) {
			if ((a[i] >> j) & 1ll) pref[i][j] = 1;
			else pref[i][j] = 0;
		}
		for (int j = 0; j < M; j++) {
			if (i) pref[i][j] += pref[i - 1][j];
		}
	}
	int q, x;
	cin >> q >> x;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--; r--;
		int res = 0;
		for (int j = 0; j < M; j++) {
			int ones = pref[r][j] - (l - 1 >= 0 ? pref[l - 1][j] : 0);
			int zero = (r - l + 1) - ones;
			int ans = C(ones, 3);
			ans += (C(ones, 1) * C(zero, 2)) % mod;
			ans %= mod;
			int cnt = (1ll << j) % mod;
			cnt *= ans; cnt %= mod;
			res += cnt; res %= mod;
		}
		cout << res << '\n';
	}


}