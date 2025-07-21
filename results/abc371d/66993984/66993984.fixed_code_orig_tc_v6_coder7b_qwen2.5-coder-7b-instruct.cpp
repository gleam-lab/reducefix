#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    vector<int> x(n + 1), p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    vector<long long> prefix_sum(n + 1);
    prefix_sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        long long result = prefix_sum[R] - prefix_sum[L - 1];
        cout << result << '\n';
    }

    return 0;
}