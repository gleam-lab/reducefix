#include <iostream>
#include <limits>

using namespace std;

int main() {
    int n;
    long long dp0 = 0, dp1 = 0, x, temp;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        temp = dp0;
        dp0 = max(dp1 + (2*x), dp0);
        dp1 = max(temp + x, dp1 + (2*x)); // Corrected the formula for dp1
    }

    cout << max(dp0, dp1) << endl;
    return 0;
}