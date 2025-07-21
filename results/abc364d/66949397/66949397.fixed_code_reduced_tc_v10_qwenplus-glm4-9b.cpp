#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

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
        m_int b, k;
        cin >> b >> k;
        
        // Using binary search to find the maximum value of the distance
        m_int low = std::numeric_limits<m_int>::min();
        m_int high = std::numeric_limits<m_int>::max();
        
        while (high - low > 1) {
            m_int mid = (low + high) / 2;
            m_int count = 0;
            for (m_int i = 0; i < n; ++i) {
                count += std::abs(a[i] - b) <= mid;
            }
            
            if (count < k) {
                low = mid;
            } else {
                high = mid;
            }
        }
        
        cout << high << "\n";
    }

    return 0;
}