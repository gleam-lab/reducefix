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
    vector<pair<m_int, m_int>> queries(q);

    for (m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    for (m_int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
        queries[i].second--; // Convert to 0-based index
    }

    // Sort queries by the distance from B_j to origin for binary search efficiency
    std::sort(queries.begin(), queries.end(), [&](const pair<m_int, m_int>& a, const pair<m_int, m_int>& b) {
        return std::abs(a.first) < std::abs(b.first);
    });

    vector<m_int> results(q);

    // Binary search to find the k_j-th closest A_i to each B_j
    for (m_int i = 0; i < q; ++i) {
        m_int b = queries[i].first;
        m_int k = queries[i].second;
        m_int dist = std::abs(b);
        m_int left = 0;
        m_int right = n - 1;
        m_int best_index = -1;

        while (left <= right) {
            m_int mid = left + (right - left) / 2;
            m_int a_dist = std::abs(a[mid] - b);
            if (mid > k) {
                // When mid is greater than k, we need to find the closest to k
                if (a_dist < dist || (a_dist == dist && mid < best_index)) {
                    best_index = mid;
                }
                right = mid - 1;
            } else if (mid < k) {
                // When mid is less than k, we need to find the closest to k+1
                dist = a_dist;
                left = mid + 1;
            } else {
                // When mid is exactly k, this is the closest point
                best_index = mid;
                break;
            }
        }

        // Calculate the distance from the closest A_i to B_j
        results[i] = std::abs(a[best_index] - b);
    }

    // Output all results
    for (m_int i = 0; i < q; ++i) {
        cout << results[i] << std::endl;
    }

    return 0;
}