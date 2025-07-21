#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using m_int = long long;
using std::cin;
using std::cout;
using std::vector;

int main() {
    m_int n, q; cin >> n >> q;
    vector<m_int> a(n);
    
    for (m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    while (q--) {
        m_int b, k; cin >> b >> k;

        auto count_points_within_distance = [&](m_int x) -> m_int {
            auto it_l = std::lower_bound(a.begin(), a.end(), b - x);
            auto it_r = std::upper_bound(a.begin(), a.end(), b + x);
            return it_r - it_l;
        };

        m_int left = 0;
        m_int right = 2e18; // Sufficiently large to cover all possible distances
        m_int answer = 0;

        while (left <= right) {
            m_int mid = left + (right - left) / 2;
            m_int count = count_points_within_distance(mid);
            if (count >= k) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << answer << "\n";
    }
    return 0;
}