#include <vector>
#include <iostream>
#include <algorithm>

using m_int = long long;
using std::cin;
using std::cout;
using std::vector;

int main() {
    std::ios::sync_with_stdio(false);
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

        // Binary search on the answer (distance)
        m_int low = 0, high = 2e8 + 1; // Max possible distance is ~2*1e8

        auto countPointsWithinDistance = [&](m_int x) {
            // Find the range [b - x, b + x] in sorted array a
            auto left = lower_bound(a.begin(), a.end(), b - x);
            auto right = upper_bound(a.begin(), a.end(), b + x);
            return static_cast<m_int>(right - left);
        };

        while (low < high) {
            m_int mid = (low + high) / 2;
            if (countPointsWithinDistance(mid) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        cout << low << "\n";
    }

    return 0;
}