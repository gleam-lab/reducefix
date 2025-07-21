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

    while (q--) {
        m_int b, k;
        cin >> b >> k;

        // Sort points A to find the median for initial binary search range
        std::sort(a.begin(), a.end());

        auto f = [&](m_int x) -> bool {
            int count = 0;
            for (m_int i = 0; i < n; ++i) {
                if (std::abs(a[i] - b) <= x) {
                    ++count;
                }
            }
            return count >= k;
        };

        m_int l = 0;
        m_int r = 2 * 1e8 + 1;
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