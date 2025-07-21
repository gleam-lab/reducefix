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
    vector<m_int> a(n), b_indices(n);
    
    for (m_int i = 0; i < n; ++i) {
        cin >> a[i];
        b_indices[i] = i + 1;  // Storing index + 1 for 1-based indexing in queries.
    }

    for (m_int i = 0; i < q; ++i) {
        m_int b, k; cin >> b >> k;
        // Using the nth_element to find the k-th closest point to b.
        std::nth_element(a.begin(), a.begin() + k - 1, a.end(), 
                         [b](m_int x, m_int y) { return std::abs(x - b) < std::abs(y - b); });
        // Calculate and print the distance to the k-th closest point.
        cout << std::abs(a[k - 1] - b) << std::endl;
    }

    return 0;
}