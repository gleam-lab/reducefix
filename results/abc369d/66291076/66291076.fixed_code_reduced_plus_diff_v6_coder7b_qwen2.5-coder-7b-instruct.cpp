#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    // Edge case handling
    if(n == 1) {
        cout << a[0] << endl;
        return 0;
    }
    if(n == 2) {
        cout << a[0] + 2 * a[1] << endl;
        return 0;
    }

    // Initialize DP arrays
    vector<long long> dp_odd(n, 0), dp_even(n, 0);
    dp_odd[0] = a[0];
    dp_even[0] = 0;
    dp_odd[1] = a[1];
    dp_even[1] = a[0] + 2 * a[1];

    // Fill DP tables
    for(int i = 2; i < n; ++i) {
        dp_odd[i] = max(dp_odd[i-2] + 2*a[i], dp_even[i-1] + a[i]);
        dp_even[i] = max(dp_even[i-2] + a[i], dp_odd[i-1] + 2*a[i]);
    }

    // Output the maximum value from either DP array
    cout << max(dp_odd[n-1], dp_even[n-1]) << endl;

    return 0;
}