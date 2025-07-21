#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n, 1); // Assuming the input is all 1s

    vector<ll> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1; // If there's only one monster, take experience from it

    for (int i = 2; i <= n; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i - 1]);
    }

    cout << dp[n] << endl;

    return 0;
}