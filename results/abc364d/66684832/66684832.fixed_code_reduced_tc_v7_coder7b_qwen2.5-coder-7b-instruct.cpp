#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n), b(q), k(q);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < q; ++i) {
        cin >> b[i] >> k[i];
    }

    // Sort points A
    sort(a.begin(), a.end());

    // Calculate prefix sums of distances
    vector<ll> prefix_sums(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sums[i + 1] = prefix_sums[i] + abs(a[i]);
    }

    // Process each query
    for (int i = 0; i < q; ++i) {
        ll target_distance = k[i];
        ll left = 0, right = 1e8;
        while (left < right) {
            ll mid = (left + right) / 2;
            auto it = lower_bound(a.begin(), a.end(), b[i] - mid);
            int count_less_than_mid = it - a.begin();
            auto it2 = upper_bound(a.begin(), a.end(), b[i] + mid);
            int count_greater_than_mid = a.end() - it2;
            int total_count = count_less_than_mid + count_greater_than_mid;

            if (total_count >= target_distance) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        // Calculate the exact k-th smallest distance
        int count_less_than_left = lower_bound(a.begin(), a.end(), b[i] - left) - a.begin();
        ll kth_distance = prefix_sums[count_less_than_left + target_distance - 1] - prefix_sums[count_less_than_left];

        cout << kth_distance << endl;
    }

    return 0;
}