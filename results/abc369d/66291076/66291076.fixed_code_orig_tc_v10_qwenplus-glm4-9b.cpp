#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void insert_and_sort(vector<ll>& v, ll val) {
    auto it = lower_bound(v.begin(), v.end(), val);
    v.insert(it, val);
}

int main() {
    int n;
    cin >> n;
    vector<ull> a(n + 1, 0); // Use unsigned long long to handle large values
    for (int i = 0; i < n; ++i) {
        cin >> a[i + 1];
    }

    // Early return for small n
    if (n == 1) {
        cout << a[1] << endl;
        return 0;
    } else if (n == 2) {
        cout << a[1] + 2 * a[2] << endl;
        return 0;
    }

    vector<ll> dp_odd(n + 1, 0), dp_even(n + 1, 0);
    dp_odd[1] = a[1];
    dp_even[2] = a[1] + 2 * a[2]; // Corrected the index for dp_even initialization

    for (int i = 3; i <= n; ++i) {
        dp_odd[i] = max(dp_odd[i - 2] + 2 * a[i], dp_even[i - 1] + a[i]);
        dp_even[i] = max(dp_even[i - 2] + a[i], dp_odd[i - 1] + 2 * a[i]);
    }

    cout << max(dp_odd[n], dp_even[n - 1]) << endl; // Corrected the index for dp_even

    return 0;
}