#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int n;
    ll x;
    cin >> n;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    // Initialize dp arrays for storing the maximum possible experience after i elements
    // when considering odd and even turns
    vector<ll> dp_odd(n + 1), dp_even(n + 1);
    
    // Base cases
    dp_odd[0] = 0; // No experience yet
    dp_even[0] = 0;
    dp_odd[1] = a[0];
    dp_even[1] = 2 * a[0];

    // Fill dp arrays
    for (int i = 2; i <= n; ++i) {
        dp_odd[i] = max(dp_odd[i - 2] + 2 * a[i - 1], dp_even[i - 1] + a[i - 1]);
        dp_even[i] = max(dp_even[i - 2] + a[i - 1], dp_odd[i - 1] + 2 * a[i - 1]);
    }

    // The result is the maximum of the last elements in the dp arrays
    cout << max(dp_odd[n], dp_even[n]) << endl;

    return 0;
}