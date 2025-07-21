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
        
        // Find the position of L and R in the sorted array of x values
        auto itL = lower_bound(x.begin() + 1, x.end(), L) - x.begin();
        auto itR = upper_bound(x.begin() + 1, x.end(), R) - x.begin();
        
        // Calculate the prefix sum difference for the corresponding indices in p
        long long result = sum[itR - 1] - sum[itL - 1];
        
        cout << result << endl;
    }
    
    return 0;
}