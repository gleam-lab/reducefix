#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define inf 1e9+7

using namespace std;

int qpowm(int a, int b, int m) {
	int r = 1;
	while (b) {
		if (b & 1)(r *= a) %= m;
		(a *= a) %= m, b >>= 1;
	}
	return r;
}

int qpow(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1)r *= a;
		a *= a;
		b >>= 1;
	}
	return r;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<set<int>>rows(n + 1), cols(n + 1), diag1(2 * n + 1), diag2(2 * n + 1);

	for (int i = 1, x, y; i <= m; i++) {
		cin >> x >> y;
		rows[x].insert(y);
		cols[y].insert(x);
		diag1[x + y].insert(x);
		diag2[x - y + n].insert(x); // To handle negative indices properly
	}

	int ans = n * n;

	for (int i = 1; i <= n; i++) {
		if (!rows[i].empty()) {
			ans -= (n - rows[i].size());
		}
		if (!cols[i].empty()) {
			ans -= (n - cols[i].size());
		}
	}

	for (int i = 1; i <= 2 * n; i++) {
		if (!diag1[i].empty()) {
			ans -= (n - diag1[i].size());
		}
		if (!diag2[i].empty()) {
			ans -= (n - diag2[i].size());
		}
	}

	cout << ans << endl;
}

signed main() {
	int _ = 1;
//	cin>>_;
	while (_) {
		solve();
	}

	return 0;
}