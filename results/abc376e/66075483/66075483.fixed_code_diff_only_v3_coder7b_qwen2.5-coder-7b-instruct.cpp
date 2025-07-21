#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pii> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }

        // Sort based on A_i in descending order
        sort(a.begin(), a.end(), greater<pii>());
        // Sort based on B_i in ascending order
        sort(b.begin(), b.end());

        int ans = INT_MAX;
        int prefix_sum_b = 0;
        for (int i = 0; i < k - 1; ++i) {
            prefix_sum_b += b[i].first;
        }

        for (int i = 0; i <= n - k; ++i) {
            int max_a = a[i].first;
            int sum_b = prefix_sum_b + b[i + k - 1].first;
            ans = min(ans, max_a * sum_b);
        }

        cout << ans << '\n';
    }

    return 0;
}