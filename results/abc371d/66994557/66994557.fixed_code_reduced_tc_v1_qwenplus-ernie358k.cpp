#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<long long> x(n + 1), p(n + 1), sum(n + 1, 0);
    
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
        
        auto it_l = lower_bound(x.begin() + 1, x.end(), L) - x.begin();
        auto it_r = upper_bound(x.begin() + 1, x.end(), R) - x.begin();
        
        // Since we use 1-based indexing for x, we need to adjust for 0-based indexing of iterators
        cout << sum[it_r - 1] - sum[it_l - 1] << endl;
    }
    
    return 0;
}