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
            // Count how many points have distance less than or equal to x
            return std::count_if(a.begin(), a.end(), [b, x](m_int ai) { return std::abs(ai - b) <= x; }) >= k;
        };

        m_int l = 0;
        m_int r = 1e8;
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