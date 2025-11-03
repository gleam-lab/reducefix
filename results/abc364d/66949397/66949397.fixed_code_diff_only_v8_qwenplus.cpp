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
    
    for(m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    while(q--) {
        
        m_int b, k; cin >> b >> k;
        
        // Binary search on the answer (distance)
        m_int l = -1;
        m_int r = 2e8 + 1; // Maximum possible distance is 2*10^8
        
        while(l + 1 < r) {
            m_int mid = (l + r) / 2;
            
            // Count how many points A_i are within distance 'mid' from point B
            auto it_l = std::lower_bound(a.begin(), a.end(), b - mid);
            auto it_r = std::upper_bound(a.begin(), a.end(), b + mid);
            m_int count = it_r - it_l;
            
            if (count >= k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << r << "\n";
    }
}