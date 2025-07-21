#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<long long> x(n + 1), p(n + 1), sum(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    
    cin >> q;
    while (q--) {
        long long L, R;
        cin >> L >> R;
        
        auto it_l = lower_bound(x.begin() + 1, x.end(), L) - x.begin();
        auto it_r = upper_bound(x.begin() + 1, x.end(), R) - x.begin();
        
        // Since it_l and it_r are 0-based indices but our sum array is 1-based,
        // we need to adjust indices accordingly.
        // Additionally, make sure to handle cases where lower_bound or upper_bound
        // go out of the valid range (though in this specific problem, it should not happen).
        cout << sum[it_r - 1] - sum[it_l - 1] << endl;
    }
    
    return 0;
}