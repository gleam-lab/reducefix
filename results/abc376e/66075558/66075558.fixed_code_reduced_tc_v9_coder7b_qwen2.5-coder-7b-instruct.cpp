#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN = 2e5 + 9, INF = 0x3f3f3f3f3f3f3f3f;

int n, k, ans;
vector<pair<int, int>> a, b;

void solve() {
    a.clear(), b.clear();
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int ai, bi; cin >> ai >> bi;
        a.emplace_back(ai, i);
        b.emplace_back(bi, i);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long sum_b = 0;
    for (int i = 0; i < k; ++i) {
        sum_b += b[i].first;
    }
    ans = sum_b * a[k - 1].first;

    for (int i = k; i < n; ++i) {
        sum_b -= b[i - k].first;
        sum_b += b[i].first;
        ans = min(ans, sum_b * a[i].first);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}