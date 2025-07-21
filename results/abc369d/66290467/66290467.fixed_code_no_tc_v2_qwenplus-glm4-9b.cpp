#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    } else if (n == 2) {
        cout << a[0] + 2 * a[1] << endl;
        return 0;
    }

    vector<int> dp(n);
    dp[0] = a[0];
    dp[1] = dp[0] + 2 * a[1];

    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 2] + 2 * a[i], dp[i - 1] + a[i]);
    }
    cout << dp[n - 1] << endl;

    return 0;
}