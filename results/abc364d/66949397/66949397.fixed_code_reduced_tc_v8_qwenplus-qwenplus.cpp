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
    sort(a.begin(), a.end());

    while(q--) {
        m_int b, k;
        cin >> b >> k;

        // Binary search on the answer (distance)
        m_int low = 0, high = 2e14;  // Increased upper bound
        m_int answer = high;

        while (low <= high) {
            m_int mid = (low + high) / 2;

            // Find the range of points within distance mid from b
            auto left = lower_bound(a.begin(), a.end(), b - mid);
            auto right = upper_bound(a.begin(), a.end(), b + mid);

            if (right - left >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << answer << "\n";
    }
}