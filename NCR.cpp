#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

const int N = 1e5;
const int mod = 1e9 + 7;

int fact[N];

int powr(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res *= a;
        res %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return powr(a, mod - 2);
}

void pre_cal() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = i * fact[i - 1];
        fact[i] %= mod;
    }
}

// NCR%mod
int NCR(int n, int r) {
    int num = fact[n];
    int den = (fact[r] * fact[n - r]) % mod;
    int res = (num * inv(den)) % mod;
    return res;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // code
    pre_cal();
    cout << NCR(5, 3);
}