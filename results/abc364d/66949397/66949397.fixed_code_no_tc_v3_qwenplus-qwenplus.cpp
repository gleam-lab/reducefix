#include <vector>
#include <iostream>
#include <algorithm>

using m_int = long long;
using std::cin;
using std::cout;
using std::vector;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
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
        m_int left = 0;
        m_int right = 2e8 + 1; // Max possible distance + buffer

        auto count_points_within_distance = [&](m_int x) {
            // Find the first A_i >= b - x
            auto low = lower_bound(a.begin(), a.end(), b - x);
            // Find the last A_i <= b + x
            auto high = upper_bound(a.begin(), a.end(), b + x);
            return high - low;
        };

        // Binary search to find the k-th smallest distance
        while(left < right) {
            m_int mid = (left + right) / 2;
            if(count_points_within_distance(mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        cout << left << "\n";
    }

    return 0;
}