#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

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

        // We need to find the k-th closest distance to b
        // We need to consider distances from a_i to b, which are |a_i - b|
        // We will use binary search to find the smallest distance that is at least k-th smallest
        auto is_valid = [&](m_int x) {
            m_int count = 0;
            for (m_int ai : a) {
                if (std::abs(ai - b) <= x) count++;
            }
            return count >= k;
        };

        m_int left = 0, right = 1e18;
        while (left + 1 < right) {
            m_int mid = (left + right) / 2;
            if (is_valid(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        cout << right << "\n";
    }
}