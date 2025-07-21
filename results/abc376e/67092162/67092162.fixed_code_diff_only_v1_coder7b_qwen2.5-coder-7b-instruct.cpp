#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int t, n, k, a[MAXN], b[MAXN];

struct Pair {
    int first, second;
};

bool cmp(Pair p1, Pair p2) {
    if (p1.first != p2.first) return p1.first > p2.first;
    return p1.second > p2.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<Pair> pairs(n);
        long long sum = 0, ans = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
            pairs[i] = {a[i], b[i]};
        }

        sort(pairs.begin(), pairs.end(), cmp);

        for (int i = 0; i < k; ++i) {
            sum += pairs[i].second;
        }

        ans = min(ans, static_cast<long long>(pairs[k - 1].first) * sum);

        for (int i = k; i < n; ++i) {
            if (pairs[i].second > pairs[i - k].second) {
                sum -= pairs[i - k].second;
                sum += pairs[i].second;
                ans = min(ans, static_cast<long long>(pairs[i].first) * sum);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}