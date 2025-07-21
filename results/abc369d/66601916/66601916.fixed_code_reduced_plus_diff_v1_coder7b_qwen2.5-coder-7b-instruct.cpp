#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n == 0) {
        cout << "0" << endl;
        return 0;
    }
    
    vector<long long> dp(n, 0);
    dp[0] = INT_MIN / 2; // Initialize with a value smaller than any possible sum
    
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        
        for (int j = i; j >= 0; --j) {
            if (j == 0) {
                dp[j] = max(dp[j], x);
            } else {
                dp[j] = max(dp[j], dp[j-1] + 2 * x);
            }
        }
    }
    
    cout << dp[n-1] << endl;
    return 0;
}