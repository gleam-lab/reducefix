#include <vector>
#include <iostream>
#include <algorithm>

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
    std::sort(a.begin(), a.end());

    while (q--) {
        m_int b, k; cin >> b >> k;
        // Calculate the distance to the k-th closest point
        auto distance_to_kth_point = a[k - 1] - b;
        cout << distance_to_kth_point << "\n";
    }
}