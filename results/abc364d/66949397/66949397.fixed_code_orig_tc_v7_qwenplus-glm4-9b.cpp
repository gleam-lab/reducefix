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
    for (m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while (q--) {
        m_int b, k; cin >> b >> k;
        // Find the k-th closest point
        auto it = std::next(std::lower_bound(a.begin(), a.end(), b), k - 1);
        m_int dist = std::abs(*it - b);
        cout << dist << "\n";
    }
}