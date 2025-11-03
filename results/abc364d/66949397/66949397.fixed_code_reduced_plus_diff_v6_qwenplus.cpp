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
    
    for(m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    while(q--) {
        
        m_int b, k;
        cin >> b >> k;

        // Binary search on the distance
        auto f = [&](m_int x) -> bool {
            // Count how many points in A are within distance x from B
            // We want to check if at least k points are within distance x
            auto it_l = std::lower_bound(a.begin(), a.end(), b - x);
            auto it_r = std::upper_bound(a.begin(), a.end(), b + x);
            return (it_r - it_l) >= k;
        };

        // Set bounds correctly - maximum possible distance is huge
        m_int l = -1; 
        m_int r = 2e9; // Increased upper bound to handle large coordinate differences
        
        while(l + 1 < r) {
            m_int mid = (l + r) / 2;
            if (f(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << r << "\n";
    }
}