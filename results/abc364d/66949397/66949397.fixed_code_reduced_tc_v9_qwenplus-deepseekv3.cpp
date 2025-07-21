#include <vector>
#include <iostream>
#include <algorithm>

using m_int = long long;
using std::cin;
using std::cout;
using std::vector;
using std::lower_bound;
using std::upper_bound;

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
            auto left = lower_bound(a.begin(), a.end(), b - x);
            auto right = upper_bound(a.begin(), a.end(), b + x);
            return (right - left) >= k;
        };

        m_int l = -1;
        m_int r = 2e18; // Sufficiently large to cover all possible distances
        while (l + 1 < r) {
            m_int mid = l + (r - l) / 2;
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