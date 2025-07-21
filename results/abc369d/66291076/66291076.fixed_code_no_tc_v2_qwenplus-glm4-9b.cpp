#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    } else if (n == 2) {
        cout << a[0] + 2 * a[1] << endl;
        return 0;
    }

    vector<long long> dp_odd(n + 1, 0), dp_even(n + 1, 0);
    dp_odd[1] = a[0];
    dp_even[1] = 0;
    dp_odd[2] = a[1];
    dp_even[2] = a[0] + 2 * a[1];

    for (int i = 3; i <= n; i++) {
        dp_odd[i] = max(dp_odd[i - 2] + 2 * a[i - 1], dp_even[i - 1] + a[i]);
        dp_even[i] = max(dp_even[i - 2] + a[i - 1], dp_odd[i - 1] + 2 * a[i]);
    }

    cout << max(dp_odd[n], dp_even[n]) << endl;

    return 0;
}