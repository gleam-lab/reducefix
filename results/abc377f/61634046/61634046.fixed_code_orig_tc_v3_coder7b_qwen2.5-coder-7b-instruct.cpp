#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> row(n + 1), col(n + 1);
    vector<set<pair<int, int>>> diag1(2 * n), diag2(2 * n);

    for(int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        row[y]++;
        col[x]++;
        diag1[x - y].insert({x, y});
        diag2[x + y].insert({x, y});
    }

    ll ans = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(!row[j] && !col[i] && diag1[i - j].size() == 1 && diag2[i + j].size() == 1) {
                ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}