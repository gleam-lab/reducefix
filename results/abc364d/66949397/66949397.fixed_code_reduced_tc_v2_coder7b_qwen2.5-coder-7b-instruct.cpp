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

        auto count_within_range = [&](m_int max_distance) {
            m_int count = 0;
            for (m_int ai : a) {
                if (std::abs(ai - b) <= max_distance) {
                    ++count;
                }
            }
            return count;
        };

        m_int left = 0, right = 2 * 1e8 + 1;
        while (left < right) {
            m_int mid = (left + right) / 2;
            if (count_within_range(mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        cout << left << "\n";
    }

    return 0;
}