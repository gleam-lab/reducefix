#include <vector>
#include <iostream>
#include <algorithm>

using m_int = long long;
using std::cin;
using std::cout;
using std::vector;

int main() {
    m_int n, q;
    cin >> n >> q;
    vector<m_int> a(n), b(q);

    // Read coordinates of A points
    for (m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Read coordinates of B points and their respective k values
    for (m_int i = 0; i < q; ++i) {
        cin >> b[i] >> a[i + n]; // Store k values in a[n:]
    }

    // Combine all points and sort them
    vector<m_int> all_points(a.begin(), a.end());
    std::sort(all_points.begin(), all_points.end());

    while (q--) {
        m_int b_val = b[q];
        m_int k_val = a[q + n];

        auto f = [&](m_int x) -> bool {
            // Count points in A within distance x from B_val
            int count = 0;
            auto it = std::lower_bound(all_points.begin(), all_points.end(), b_val - x);
            for (; it != all_points.end(); ++it) {
                if (*it - b_val > x) break;
                count++;
            }
            return count >= k_val;
        };

        m_int l = -1;
        m_int r = 1e9 + 1; // Adjusted upper bound based on constraints
        while (l + 1 < r) {
            m_int mid = (l + r) / 2;
            if (f(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << r << "\n";
    }

    return 0;
}