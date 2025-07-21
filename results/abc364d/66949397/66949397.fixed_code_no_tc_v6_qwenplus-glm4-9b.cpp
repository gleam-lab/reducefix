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

    vector<m_int> results(q, 0); // Preallocate space for results

    while (q--) {
        m_int b, k;
        cin >> b >> k;

        // We need to find the (k-j)-th smallest distance to B_j
        // Calculate the maximum possible distance to B_j that can be the (k-j)-th smallest
        m_int max_dist = std::min(b - a.front(), a.back() - b) + 1; // max distance is a_i to b_j or b_j to a_N

        // Binary search to find the smallest distance that is the (k-j)-th smallest
        m_int left = 0, right = max_dist;
        while (left < right) {
            m_int mid = (left + right + 1) / 2;
            auto count = std::count_if(a.begin(), a.end(), [&](m_int x) {
                return std::abs(x - b) >= mid; // Count elements that are far enough
            });
            if (count < k) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        results[q] = left; // Store the result
    }

    // Output all results
    for (m_int result : results) {
        cout << result << "\n";
    }

    return 0;
}