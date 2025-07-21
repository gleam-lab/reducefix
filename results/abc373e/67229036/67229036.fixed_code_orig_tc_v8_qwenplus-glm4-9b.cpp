#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // Sort the votes and compute the cumulative sum
    sort(a.begin(), a.end());
    vector<int> prefix_sum(n);
    prefix_sum[0] = a[0];
    for (int i = 1; i < n; ++i) prefix_sum[i] = prefix_sum[i - 1] + a[i];

    // Function to check if candidate i can guarantee victory with x additional votes
    auto can_guarantee = [&](int i, int x) {
        int votes_needed = m * a[i] - (prefix_sum[i - 1] + max(x, a[n - m]));
        return (i >= m) ? votes_needed <= (prefix_sum[n - 1] - prefix_sum[i - 1] - x) : votes_needed <= (prefix_sum[n - 1] - prefix_sum[i - 1] - x);
    };

    for (int i = 0; i < n; ++i) {
        if (m == 1 || i < m - 1) {
            cout << 0 << " ";
            continue;
        }

        int low = 0, high = k + 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (can_guarantee(i, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        if (low <= k) cout << low << " ";
        else cout << -1 << " ";
    }

    return 0;
}