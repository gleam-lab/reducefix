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
    sort(a.begin(), a.end());
    
    while (q--) {
        m_int b, k;
        cin >> b >> k;
        
        auto lower = std::lower_bound(a.begin(), a.end(), b);
        auto upper = std::upper_bound(a.begin(), a.end(), b);
        
        if (k > upper - a.begin()) {
            cout << *std::prev(upper, k - (upper - a.begin())) - b << "\n";
        } else {
            cout << *lower - b << "\n";
        }
    }
}