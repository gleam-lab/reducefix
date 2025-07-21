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
        
        // Binary search for the smallest distance that is >= k-th closest
        m_int low = -1e8 - 1, high = 1e8 + 1;
        while (low + 1 < high) {
            m_int mid = (low + high) / 2;
            m_int count = 0;
            for (m_int i = 0; i < n; ++i) {
                if (std::abs(a[i] - b) >= mid) {
                    count++;
                }
            }
            if (count >= k) {
                high = mid;
            } else {
                low = mid;
            }
        }
        
        // Output the distance of the k-th closest point
        cout << high << "\n";
    }
}