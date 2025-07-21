#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

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
    std::sort(a.begin(), a.end());

    while (q--) {
        m_int b, k; 
        cin >> b >> k;

        auto f = [&](m_int x) -> bool {
            // Points in A are >= b - x and <= b + x
            auto it_l = std::lower_bound(a.begin(), a.end(), b - x);
            auto it_r = std::upper_bound(a.begin(), a.end(), b + x);
            return (it_r - it_l) >= k;
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
}