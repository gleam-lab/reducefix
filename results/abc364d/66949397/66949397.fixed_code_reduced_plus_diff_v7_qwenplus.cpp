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

        // Binary search on the answer (distance)
        auto f = [&](m_int x) -> bool {
            // Count how many points in A are within distance x from point b
            // That is: |a_i - b| <= x  =>  b-x <= a_i <= b+x
            auto it_l = std::lower_bound(a.begin(), a.end(), b - x);
            auto it_r = std::upper_bound(a.begin(), a.end(), b + x);
            return (it_r - it_l) >= k;
        };

        // Set bounds correctly to handle large coordinate ranges
        m_int l = -1;
        // Maximum possible distance is when coordinates are at extremes
        m_int r = 2e9;  // Since coordinates can be up to 2e8 apart

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