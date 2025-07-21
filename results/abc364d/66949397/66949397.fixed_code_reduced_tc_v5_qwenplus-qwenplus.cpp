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

        // Binary search on the answer
        m_int left = 0, right = 2e14; // Safe upper bound

        auto count_in_range = [&](m_int x) {
            // Find first A_i >= (b - x)
            auto lo = lower_bound(a.begin(), a.end(), b - x);
            // Find last A_i <= (b + x)
            auto hi = upper_bound(a.begin(), a.end(), b + x);
            return hi - lo;
        };

        // Binary search to find minimal distance with at least k points in range
        while (left < right) {
            m_int mid = (left + right) / 2;
            if (count_in_range(mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        cout << left << "\n";
    }

    return 0;
}