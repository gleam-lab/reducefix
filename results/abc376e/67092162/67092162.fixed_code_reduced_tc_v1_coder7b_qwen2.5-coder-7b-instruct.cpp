#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
int t, n, k, a[maxN], b[maxN];

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.first != p2.first) return p1.first < p2.first;
    return p1.second < p2.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<pair<int, int>> p(n);
        long long sum = 0, ans = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            p[i] = {a[i], b[i]};
        }

        sort(p.begin(), p.end(), cmp);

        for (int i = 0; i < k; ++i) {
            sum += p[i].second;
        }

        ans = min(ans, static_cast<long long>(p[k - 1].first) * sum);

        for (int i = k; i < n; ++i) {
            sum += p[i].second - p[i - k].second;
            ans = min(ans, static_cast<long long>(p[i].first) * sum);
        }

        cout << ans << "\n";
    }

    return 0;
}