#include <iostream>
#include <vector>
#include <limits>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Early return for n == 1 and n == 2
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    } else if (n == 2) {
        cout << a[0] + 2 * a[1] << endl;
        return 0;
    }

    // Initialize dp arrays
    vector<ll> dp_odd(n + 1, 0), dp_even(n + 1, 0);
    dp_odd[0] = a[0];
    dp_even[0] = 0;
    dp_odd[1] = a[1];
    dp_even[1] = a[0] + 2 * a[1];

    // Fill dp arrays
    for (int i = 2; i <= n; ++i) {
        dp_odd[i] = max(dp_odd[i - 2] + 2 * a[i - 1], dp_even[i - 1] + a[i - 1]);
        dp_even[i] = max(dp_even[i - 2] + a[i - 1], dp_odd[i - 1] + 2 * a[i - 1]);
    }

    // Output the result
    cout << max(dp_odd[n], dp_even[n]) << endl;

    return 0;
}