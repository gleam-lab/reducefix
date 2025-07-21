#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<long long> x(n + 1), p(n + 1); // Use long long to handle large numbers
    map<long long, long long> prefixSum; // Using map to store prefix sums efficiently
    
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    
    long long totalPower = 0;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        totalPower += p[i];
        prefixSum[x[i]] = totalPower; // Store prefix sum at each x[i] position
    }
    
    cin >> q;
    while (q--) {
        long long L, R;
        cin >> L >> R;
        
        // Use lower_bound and upper_bound to find the positions in sorted x array
        auto itL = lower_bound(x.begin() + 1, x.end(), L);
        auto itR = upper_bound(x.begin() + 1, x.end(), R);
        
        // Convert iterators to indices
        int indexL = itL - x.begin();
        int indexR = itR - x.begin();
        
        // If indexL is still pointing to the beginning (i.e., L is smaller than all x[i]), use prefix sum at 0 (implicitly 0)
        // If indexR has gone past the end (i.e., R is larger than all x[i]), use the total prefix sum
        long long sumL = (indexL == 1 ? 0 : prefixSum[*(itL - 1)]);
        long long sumR = (indexR == n + 1 ? totalPower : prefixSum[*(itR - 1)]);
        
        cout << sumR - sumL << endl;
    }
    
    return 0;
}