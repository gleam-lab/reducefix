#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

int n, q, k;
vector<int> a(MAXN), b(MAXN), ans(MAXN);
map<int, int> cnt;

void solve() {
    sort(a.begin(), a.begin() + n);
    for (int i = 1; i <= n; ++i) {
        cnt[a[i - 1]] += i;
    }

    for (int i = 1; i <= q; ++i) {
        cin >> b[i] >> k;
        auto it = cnt.upper_bound(b[i]);
        --it;
        int dist = it->first - b[i];
        ans[i] = it->second + k * dist - (cnt.rbegin()->second - cnt.rbegin()->first / 2);
    }

    for (int i = 1; i <= q; ++i) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    solve();
    return 0;
}