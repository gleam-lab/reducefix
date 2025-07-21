#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, m;

int countEmpty(int x, int y, int dx, int dy) {
    int d = x + y;
    int ans = n - max(0, min(n - 1, d - dx));
    d = x - y;
    if (dx != 0 || dy != 0) {
        ans = max(ans, n - max(0, min(n - 1, abs(d) - abs(dx))));
    }
    return ans;
}

int solve() {
    cin >> n >> m;
    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    int ans = n * n - m;
    for (auto &piece : pieces) {
        int a = piece.first - 1, b = piece.second - 1;
        ans -= countEmpty(a, b, n - a, n - b);
        ans -= countEmpty(a, b, a, b);
        ans -= countEmpty(a, b, n - a, b);
        ans -= countEmpty(a, b, a, n - b);
    }

    cout << ans << endl;
    return 0;
}

signed main() {
    solve();
    return 0;
}