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
    
    for (m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    
    while (q--) {
        m_int b, k;
        cin >> b >> k;
        
        // Binary search to find the k-th closest point
        auto it = std::lower_bound(a.begin(), a.end(), b);
        if (it == a.begin()) {
            cout << (*it - b) * (k - 1) << "\n";
        } else if (it == a.end()) {
            cout << (b - *(it - 1)) * k << "\n";
        } else {
            m_int left_dist = b - *(it - 1);
            m_int right_dist = *it - b;
            m_int total_points = n;
            
            if (left_dist <= right_dist) {
                m_int idx = std::max(0LL, k - 1);
                cout << left_dist * idx << "\n";
            } else {
                m_int idx = std::min(total_points, k);
                cout << right_dist * idx << "\n";
            }
        }
    }
    
    return 0;
}