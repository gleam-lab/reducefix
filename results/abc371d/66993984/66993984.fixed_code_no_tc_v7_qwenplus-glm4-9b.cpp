#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
map<pair<int, int>, int> sum_map; // Using a map to store prefix sums with range for quick lookup

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    // Calculate prefix sums and store in a map
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        for (int j = 1; j <= n; j++) {
            if (x[j] >= L && x[j] <= R) {
                sum_map[{i, j}] = sum_map[{i - 1, j}] + p[j];
            }
        }
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;

        // Find the range of indices that fall within [L, R]
        auto lower = lower_bound(x + 1, x + n + 1, L) - x;
        auto upper = upper_bound(x + 1, x + n + 1, R) - x - 1; // -1 to make it exclusive of R

        // Output the difference in prefix sums
        cout << sum_map[{upper, n}] - sum_map[{lower - 1, n}] << endl;
    }

    return 0;
}