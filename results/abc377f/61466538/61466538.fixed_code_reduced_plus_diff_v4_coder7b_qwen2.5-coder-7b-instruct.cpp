#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e9 + 10;

vector<int> row_cnt(MAXN), col_cnt(MAXN), diag1_cnt(2 * MAXN), diag2_cnt(2 * MAXN);

void solve() {
    int n, m; cin >> n >> m;
    vector<pii> q(m);
    for(int i = 0; i < m; ++i) {
        cin >> q[i].first >> q[i].second;
        row_cnt[q[i].first]++;
        col_cnt[q[i].second]++;
        diag1_cnt[q[i].first + q[i].second]++;
        diag2_cnt[q[i].first - q[i].second + MAXN]++;
    }

    int ans = n * n;
    for(int i = 1; i <= n; ++i) {
        ans -= row_cnt[i];
        ans -= col_cnt[i];
    }
    for(int i = 1; i <= 2 * MAXN; ++i) {
        ans -= max(diag1_cnt[i], diag2_cnt[i]);
    }
    ans += m;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}