#include <vector>
#include <iostream>
#include <algorithm>

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
        
        // Binary search over the possible distances
        m_int low = 0;
        m_int high = 2e18; // Sufficiently large to cover all possible distances
        
        while (low < high) {
            m_int mid = low + (high - low) / 2;
            
            // Count the number of points with distance <= mid
            auto it_left = std::lower_bound(a.begin(), a.end(), b - mid);
            auto it_right = std::upper_bound(a.begin(), a.end(), b + mid);
            m_int count = it_right - it_left;
            
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        cout << low << "\n";
    }
    return 0;
}