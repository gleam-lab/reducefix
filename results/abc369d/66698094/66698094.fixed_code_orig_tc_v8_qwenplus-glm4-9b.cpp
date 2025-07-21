#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int MOD = 1e9 + 7, N = 200005;  // You may need to adjust the limit based on problem constraints

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<ll> v(n);
    ll dp[2];  // We can use a rolling array for optimization
    dp[0] = dp[1] = 0;  // Base cases
    
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        dp[(i + 1) % 2] = max(dp[i % 2], dp[i % 2] + v[i]);  // It's the same as taking 2 times the value because we can't take the same value twice
    }
    
    cout << max(dp[n % 2]) << '\n';
    return 0;
}