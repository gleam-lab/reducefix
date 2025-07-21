#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n;

    vector<int> x(n + 1), p(n + 1);  // Use vector for dynamic array handling and 1-based simulation
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    vector<long long> sum(n + 1);  // Use long long to handle potential overflow
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        auto it_l = lower_bound(x.begin() + 1, x.end(), l) - x.begin();  // 0-based index adjustment
        auto it_r = upper_bound(x.begin() + 1, x.end(), r) - x.begin();  // 0-based index adjustment

        // Adjust for 1-based to 0-based conversion in original array indices
        if (it_l > 0 && it_l <= n && it_r > 0 && it_r <= n) {
            cout << sum[it_r - 1] - sum[it_l - 1] << endl;
        } else {
            cout << 0 << endl;  // Handle invalid range cases, adjust as needed
        }
    }

    return 0;
}