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
            auto left = std::lower_bound(a.begin(), a.end(), b - x);
            auto right = std::upper_bound(a.begin(), a.end(), b + x);
            return (right - left) >= k;
        };

        m_int l = 0;
        m_int r = 2e14; // Sufficiently large to cover all possible distances
        m_int ans = 0;

        while (l <= r) {
            m_int mid = l + (r - l) / 2;
            if (f(mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}