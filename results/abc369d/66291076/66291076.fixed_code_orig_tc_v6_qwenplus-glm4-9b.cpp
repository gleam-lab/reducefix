#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

using ll = long long;

#define rep(i, n) for (ll(i) = 0; (i) < (n); ++(i))
#define drep(i, n) for (ll(i) = (n) - 1; (i) >= 0; --(i))

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    } else if (n == 2) {
        cout << a[0] + 2 * a[1] << endl;
        return 0;
    }

    // Initialize dp arrays
    vector<ll> dp_odd(n, 0), dp_even(n, 0);
    dp_odd[0] = a[0];
    dp_even[0] = 0;
    dp_odd[1] = a[1];
    dp_even[1] = a[0] + 2 * a[1];

    for (int i = 2; i < n; ++i) {
        // Calculate the maximum experience values for odd and even numbers of defeated creatures
        dp_odd[i] = max(dp_odd[i - 2] + 2LL * a[i], dp_even[i - 1] + a[i]);
        dp_even[i] = max(dp_even[i - 2] + a[i], dp_odd[i - 1] + 2LL * a[i]);
    }
    
    // Use long long to prevent overflow when calculating the maximum value
    cout << max(dp_odd[n - 1], dp_even[n - 1]) << endl;

    return 0;
}