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
    vector<m_int> b(q), k(q);
    
    for (m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (m_int i = 0; i < q; ++i) {
        cin >> b[i] >> k[i];
    }
    
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    for (m_int j = 0; j < q; ++j) {
        m_int b_j = b[j];
        m_int k_j = k[j];

        auto it = std::lower_bound(a.begin(), a.end(), b_j);
        m_int d_j = std::abs(b_j - *it);
        
        // Calculate the distances to the k_j-th closest point
        m_int count = 0;
        for (auto i = it; i != a.end(); ++i) {
            if (++count == k_j) {
                cout << std::abs(b_j - *i) << std::endl;
                break;
            }
        }
    }
}