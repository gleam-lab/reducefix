#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

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
            auto it_l = std::lower_bound(a.begin(), a.end(), b - x);
            auto it_r = std::upper_bound(a.begin(), a.end(), b + x);
            return (it_r - it_l) >= k;
        };

        m_int l = 0;
        m_int r = 2e14; // Sufficiently large to cover the maximum possible distance
        m_int answer = 0;

        while (l <= r) {
            m_int mid = l + (r - l) / 2;
            if (f(mid)) {
                answer = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << answer << "\n";
    }
}