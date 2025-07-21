#include <vector>
#include <iostream>
#include <algorithm>

using m_int = long long;
using std::cin;
using std::cout;
using std::vector;

bool canFindKthClosest(int N, int Q, vector<int>& a, vector<int>& b, int k) {
    for (int j = 0; j < Q; ++j) {
        int bj = b[j];
        int kj = k[j];
        
        // Count how many points A_i have a distance <= bj
        int count = 0;
        for (int ai : a) {
            if (std::abs(ai - bj) <= bj) {
                ++count;
            }
        }
        
        if (count < kj) {
            return false;
        }
    }
    return true;
}

int main() {
    m_int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    for (m_int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> b(q), k(q);
    for (m_int j = 0; j < q; ++j) {
        cin >> b[j] >> k[j];
    }
    
    // Sort the coordinates of points A
    std::sort(a.begin(), a.end());
    
    // Binary search for the maximum possible distance
    m_int low = 0, high = 1e9 + 1000000000;
    while (low < high) {
        m_int mid = (low + high) / 2;
        if (canFindKthClosest(n, q, a, b, k)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    cout << low << "\n";
    
    return 0;
}