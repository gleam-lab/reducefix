#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;
int t, n, k;
int a[maxN], b[maxN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<tuple<int, int, int>> tuples;

        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
            tuples.emplace_back(b[i], -a[i], a[i]);
        }

        sort(tuples.begin(), tuples.end());

        long long sum = 0;
        long long product = 0;
        long long ans = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            auto [bi, ai_neg, ai] = tuples[i];
            if (k > 0) {
                sum += bi;
                --k;
            } else {
                ans = min(ans, (long long)bi * product);
            }
            product -= ai_neg;
            product += ai;
        }

        ans = min(ans, (long long)sum * product);
        cout << ans << '\n';
    }

    return 0;
}