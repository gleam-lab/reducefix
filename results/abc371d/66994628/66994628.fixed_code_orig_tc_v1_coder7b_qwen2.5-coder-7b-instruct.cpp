#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n;
    vector<int> x(n), p(n + 1), prefix_sum(n + 1);

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        prefix_sum[i + 1] = prefix_sum[i] + p[i];
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l; // Adjusting for 0-based index
        cout << prefix_sum[r] - prefix_sum[l] << '\n';
    }

    return 0;
}