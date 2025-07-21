#include <vector>
#include <iostream>
#include <algorithm>

using m_int = long long;
using std::cin;
using std::cout;
using std::vector;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    m_int n, q;
    cin >> n >> q;
    vector<m_int> a(n);
    
    for (m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    while (q--) {
        m_int b, k;
        cin >> b >> k;

        // Binary search on distance
        m_int left = 0;
        m_int right = 2e8 + 1;  // Sufficient upper bound

        auto count_points_in_range = [&](m_int x) {
            // Find first a_i where a_i >= b - x
            auto lo = lower_bound(a.begin(), a.end(), b - x);
            // Find last a_i where a_i <= b + x
            auto hi = upper_bound(a.begin(), a.end(), b + x);
            return static_cast<m_int>(hi - lo);
        };

        // Binary search to find minimal x such that there are at least k points within distance x
        while (left < right) {
            m_int mid = (left + right) / 2;
            if (count_points_in_range(mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        cout << left << "\n";
    }

    return 0;
}