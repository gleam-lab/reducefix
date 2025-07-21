#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> x(n + 2), p(n + 2), prefix_sum(n + 2, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }

    int q;
    cin >> q;

    while (q--) {
        long long l, r;
        cin >> l >> r;

        // Binary search to find the first index where x[i] >= l
        int left = 1, right = n;
        int start_idx = n + 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (x[mid] >= l) {
                start_idx = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        // Binary search to find the last index where x[i] <= r
        left = 1;
        right = n;
        int end_idx = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (x[mid] <= r) {
                end_idx = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (start_idx <= end_idx) {
            cout << prefix_sum[end_idx] - prefix_sum[start_idx - 1] << "\n";
        } else {
            cout << "0\n"; // No elements in range [l, r]
        }
    }

    return 0;
}