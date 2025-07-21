#include <vector>
#include <iostream>
#include <algorithm>

using m_int = long long;
using std::cin;
using std::cout;
using std::vector;

bool canFindKthClosest(vector<m_int>& a, m_int b, m_int k, m_int dist) {
    vector<m_int> distances;
    for(auto& ai : a) {
        m_int d = abs(ai - b);
        if(d <= dist) {
            distances.push_back(d);
        }
    }
    sort(distances.begin(), distances.end());
    return distances.size() >= k;
}

int main() {
    m_int n, q;
    cin >> n >> q;
    vector<m_int> a(n);
    
    for(m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while(q--) {
        m_int b, k;
        cin >> b >> k;

        m_int left = 0, right = 1e8 + 1;
        while(left < right) {
            m_int mid = (left + right) / 2;
            if(canFindKthClosest(a, b, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        cout << left << "\n";
    }

    return 0;
}