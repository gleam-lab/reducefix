#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

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
    
    // Sort array a
    std::sort(a.begin(), a.end());

    while (q--) {
        m_int b, k;
        cin >> b >> k;

        // Calculate the range for binary search
        m_int left = 0, right = 2 * 1e8;

        while (left < right) {
            m_int mid = left + (right - left) / 2;

            // Count how many points are within the range [b-mid, b+mid]
            auto it_l = std::lower_bound(a.begin(), a.end(), b - mid);
            auto it_r = std::upper_bound(a.begin(), a.end(), b + mid);

            if (it_r - it_l >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        cout << left << "\n";
    }

    return 0;
}