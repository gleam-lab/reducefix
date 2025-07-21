#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n == 0) {
        cout << "0" << endl;
        return 0;
    }
    
    long long dp[2] = {0, INT_MIN};
    long long x;
    
    for (int i = 0; i < n; ++i) {
        cin >> x;
        long long new_dp0 = max(dp[1] + 2 * x, dp[0]);
        dp[1] = max(dp[1], dp[0] + x);
        dp[0] = new_dp0;
    }
    
    cout << max(dp[0], dp[1]) << endl;
    return 0;
}