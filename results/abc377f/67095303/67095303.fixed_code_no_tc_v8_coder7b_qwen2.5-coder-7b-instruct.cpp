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
	vector<PII> pieces(m);
	for(int i = 0; i < m; ++i){
		cin >> pieces[i].first >> pieces[i].second;
	}

	vector<bool> horizontal(n + 1), vertical(n + 1), diagonal1(2 * n + 1), diagonal2(2 * n + 1);

	for(auto [x, y] : pieces){
		horizontal[x] = true;
		vertical[y] = true;
		diagonal1[x + y] = true;
		diagonal2[x - y + n] = true;
	}

	int ans = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(!horizontal[i] && !vertical[j] && !diagonal1[i + j] && !diagonal2[i - j + n]){
				ans++;
			}
		}
	}

	cout << ans << endl;
}

signed main() {
	int _ = 1;
	while (_--){
		solve();
	}

	return 0;
}