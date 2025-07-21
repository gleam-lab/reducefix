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
    vector<m_int> a(n);

    for (m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    while (q--) {
        m_int b, k;
        cin >> b >> k;

        auto f = [&](m_int x) -> bool {
            // Binary search to find the range of elements within distance x from b
            auto it_l = std::lower_bound(a.begin(), a.end(), b - x);
            auto it_r = std::upper_bound(a.begin(), a.end(), b + x);
            return (it_r - it_l) >= k;
        };

        m_int left = -1;
        m_int right = 2e8 + 1; // Sufficiently large upper bound

        while (left + 1 < right) {
            m_int mid = (left + right) / 2;
            if (f(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        cout << right << "\n";
    }

    return 0;
}