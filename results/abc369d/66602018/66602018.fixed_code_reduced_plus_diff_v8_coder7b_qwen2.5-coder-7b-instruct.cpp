#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Initialize DP arrays
    vector<long long> dp0(n, 0), dp1(n, -1e15);

    // Fill DP arrays
    for (int i = 0; i < n; ++i) {
        dp0[i] = max(dp1[i-1] + 2 * arr[i], dp0[i-1]);
        if (i > 0) {
            dp1[i] = max(dp0[i-1] + arr[i], dp1[i-1]);
        }
    }

    // Output the result
    cout << max(dp0[n-1], dp1[n-1]) << endl;
    return 0;
}