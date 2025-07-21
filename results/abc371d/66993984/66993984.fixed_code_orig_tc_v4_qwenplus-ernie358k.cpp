#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<long long> x(n + 1), sorted_x(n + 1);
    vector<int> p(n + 1), index(n + 1);
    
    // Read x values
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        sorted_x[i] = x[i];
        index[i] = i;  // Store original indices
    }
    
    // Read p values
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    
    // Sort x values while maintaining original indices
    sort(index.begin() + 1, index.end(), [&](int a, int b) {
        return sorted_x[a] < sorted_x[b];
    });
    
    // Create a prefix sum array based on sorted indices
    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + p[index[i]];
    }
    
    cin >> q;
    while (q--) {
        long long L, R;
        cin >> L >> R;
        
        // Binary search to find the range in sorted_x
        auto it_L = lower_bound(sorted_x.begin() + 1, sorted_x.end(), L) - sorted_x.begin();
        auto it_R = upper_bound(sorted_x.begin() + 1, sorted_x.end(), R) - sorted_x.begin();
        
        // Calculate the sum using prefix sums
        long long result = (it_L <= n && sorted_x[it_L] >= L) ? prefix_sum[it_R - 1] - (it_L > 1 ? prefix_sum[it_L - 2] : 0) : 0;
        
        cout << result << endl;
    }
    
    return 0;
}