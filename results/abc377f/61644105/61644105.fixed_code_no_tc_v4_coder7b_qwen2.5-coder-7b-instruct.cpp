#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define pb push_back
#define mp make_pair
#define sz(x) ((LL)(x).size())
#define all(x) begin(x), end(x)

const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const LL LINF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e3 + 5;
int n, m;
int a[N], b[N];
vector<int> row, col, diag1, diag2;

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i] >> b[i];
        row.pb(b[i]);
        col.pb(a[i]);
        diag1.pb(a[i] + b[i]);
        diag2.pb(a[i] - b[i]);
    }
    sort(all(row));
    sort(all(col));
    sort(all(diag1));
    sort(all(diag2));

    LL ans = 0;
    int u = unique(all(row)) - row.begin();
    int v = unique(all(col)) - col.begin();
    int w = unique(all(diag1)) - diag1.begin();
    int z = unique(all(diag2)) - diag2.begin();

    ans = (LL)n * n - (LL)m * (u + v + w + z);

    for (int i = 1; i <= m; ++i) {
        int x = lower_bound(all(row), b[i]) - row.begin();
        int y = lower_bound(all(col), a[i]) - col.begin();
        int p = lower_bound(all(diag1), a[i] + b[i]) - diag1.begin();
        int q = lower_bound(all(diag2), a[i] - b[i]) - diag2.begin();

        ans += x + y + p + q - 3;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}