#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<long long> prefixSum(n + 1, 0); // Use a vector for prefix sums to handle large numbers
    
    for (int i = 0; i < n; ++i) {
        cin >> prefixSum[i + 1] = prefixSum[i] + i % m; // Compute prefix sums modulo m
    }
    
    long long ans = 0;
    for (int i = 1; i <= n; ++i) { // Start from 1 to include the case where i = 0
        for (int j = i + 1; j <= n; ++j) { // Ensure length is positive
            if ((prefixSum[j] - prefixSum[i]) % m == 0) {
                ans++;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}