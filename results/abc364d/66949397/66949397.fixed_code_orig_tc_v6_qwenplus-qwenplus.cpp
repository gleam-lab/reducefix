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

        m_int left = 0;
        m_int right = 2e8 + 1; // Upper bound on distance

        while (left < right) {
            m_int mid = (left + right) / 2;
            if (f(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        cout << left << "\n";
    }

    return 0;
}