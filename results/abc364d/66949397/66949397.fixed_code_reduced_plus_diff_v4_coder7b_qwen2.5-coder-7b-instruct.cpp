#include <vector>
#include <iostream>
#include <algorithm>

using m_int = long long;
using std::cin;
using std::cout;
using std::vector;

bool check(const vector<m_int>& sorted_points, const m_int& target, const m_int& k, const m_int& b) {
    int count = 0;
    for (const auto& point : sorted_points) {
        if (std::abs(point - b) <= target) {
            ++count;
        }
    }
    return count >= k;
}

int main() {
    m_int n, q; cin >> n >> q;
    vector<m_int> a(n);
    
    for (m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    
    while (q--) {
        m_int b, k; cin >> b >> k;
        
        // Binary search for the minimum distance
        m_int left = 0, right = 2 * 1e8; // Upper bound based on constraints
        while (left < right) {
            m_int mid = (left + right) / 2;
            if (check(a, mid, k, b)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        cout << left << "\n";
    }

    return 0;
}