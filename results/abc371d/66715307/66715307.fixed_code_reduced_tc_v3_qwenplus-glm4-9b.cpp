#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n + 1), a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a[0] = 0; // Initialize the first element to 0 for prefix sum calculation

    // Compute prefix sums
    for (int i = 1; i <= n; ++i) {
        a[i] += a[i - 1];
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        // Binary search for the range [l, r]
        int left_index = lower_bound(x.begin(), x.end(), l) - x.begin();
        int right_index = upper_bound(x.begin(), x.end(), r) - x.begin() - 1;

        // If the range is valid
        if (left_index <= right_index) {
            cout << a[right_index] - a[left_index - 1] << endl;
        } else {
            cout << "0" << endl;
        }
    }
    return 0;
}