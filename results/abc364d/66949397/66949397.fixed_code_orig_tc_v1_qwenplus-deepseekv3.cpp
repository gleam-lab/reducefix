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
        
        m_int left = 0;
        m_int right = 2e14; // Sufficiently large to cover the maximum possible distance
        
        m_int answer = 0;
        while (left <= right) {
            m_int mid = left + (right - left) / 2;
            
            auto lower = std::lower_bound(a.begin(), a.end(), b - mid);
            auto upper = std::upper_bound(a.begin(), a.end(), b + mid);
            m_int count = upper - lower;
            
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