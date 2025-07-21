#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<LL> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    // Pair and sort a and b together by a's values
    vector<pair<LL, LL>> pairs;
    for (int i = 0; i < n; ++i) pairs.emplace_back(a[i], b[i]);
    sort(pairs.begin(), pairs.end());

    // Prefix sum of b values in sorted order
    vector<LL> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + pairs[i].second;

    int m;
    cin >> m;

    while (m--) {
        LL l, r;
        cin >> l >> r;

        // Binary search to find range [l, r] in a
        auto left = lower_bound(pairs.begin(), pairs.end(), make_pair(l, numeric_limits<LL>::min()));
        auto right = upper_bound(pairs.begin(), pairs.end(), make_pair(r, numeric_limits<LL>::max()));

        int li = left - pairs.begin();
        int ri = right - pairs.begin();

        cout << prefix[ri] - prefix[li] << "\n";
    }

    return 0;
}