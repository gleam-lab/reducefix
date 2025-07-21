#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<long long> x(n + 1), p(n + 1); // Use vector for dynamic array handling and to avoid off-by-one errors
    vector<long long> sum(n + 1, 0);     // Prefix sum array
    
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    
    cin >> q;
    while (q--) {
        long long L, R;
        cin >> L >> R;
        
        // Find the positions in the sorted x array that correspond to L and R
        auto it_l = lower_bound(x.begin() + 1, x.end(), L) - x.begin();
        auto it_r = upper_bound(x.begin() + 1, x.end(), R) - x.begin();
        
        // Adjust indices to 0-based for prefix sum array access
        long long result = sum[it_r - 1] - sum[it_l - 1];
        
        cout << result << endl;
    }
    
    return 0;
}