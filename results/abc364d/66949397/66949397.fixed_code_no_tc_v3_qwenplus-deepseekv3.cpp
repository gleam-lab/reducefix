#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

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
        
        auto count_leq = [&](m_int x) -> m_int {
            // Count the number of elements in a with distance <= x from b
            auto it_r = std::upper_bound(a.begin(), a.end(), b + x);
            auto it_l = std::lower_bound(a.begin(), a.end(), b - x);
            return it_r - it_l;
        };

        m_int low = 0;
        m_int high = 2e18; // Sufficiently large to cover all possible distances
        m_int answer = 0;
        
        while (low <= high) {
            m_int mid = low + (high - low) / 2;
            m_int cnt = count_leq(mid);
            
            if (cnt >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << answer << "\n";
    }
    return 0;
}