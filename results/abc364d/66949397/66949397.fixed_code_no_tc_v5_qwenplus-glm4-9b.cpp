#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

using m_int = long long;
using std::cin;
using std::cout;
using std::vector;

int main() {
    m_int n, q;
    cin >> n >> q;
    vector<m_int> a(n);
    
    // Reading the points A
    for (m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the points A for closest distance calculation
    std::sort(a.begin(), a.end());

    // Prepare a vector to store the results
    vector<m_int> results(q);

    // Process each query B_j and k_j
    for (m_int j = 0; j < q; ++j) {
        m_int b, k;
        cin >> b >> k;

        // Use binary search to find the k-th closest point A_i to B_j
        m_int dist = std::numeric_limits<m_int>::max();
        for (m_int i = 0; i < n; ++i) {
            m_int d = std::abs(b - a[i]); // Calculate the distance from B_j to A_i
            if (i == k - 1 || (i > k - 1 && d < dist)) { // Check if it's the k-th closest or closer than current close distance
                dist = d;
            }
        }
        results[j] = dist; // Store the result
    }

    // Output the results for each query
    for (m_int j = 0; j < q; ++j) {
        cout << results[j] << "\n";
    }

    return 0;
}