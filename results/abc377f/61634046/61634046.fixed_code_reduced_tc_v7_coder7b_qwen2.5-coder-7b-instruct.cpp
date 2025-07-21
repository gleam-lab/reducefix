#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> rows(n + 1), cols(n + 1), ups[n + 1], downs[n + 1];
    for (int i = 1; i <= n; ++i) {
        ups[i].resize(n + 1);
        downs[i].resize(n + 1);
    }

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        rows[y]++;
        cols[x]++;
        ups[x + y][y]++;
        downs[x - y + n][y]++;
    }

    long long total = 1LL * n * n;
    for (int i = 1; i <= n; ++i) {
        total -= rows[i] + cols[i] - 1;
        total -= ups[i].back();
        total -= downs[i].back();
    }

    cout << (total + MOD) % MOD << endl;

    return 0;
}