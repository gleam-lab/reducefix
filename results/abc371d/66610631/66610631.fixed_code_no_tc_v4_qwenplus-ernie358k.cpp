#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = c[i - 1] + b[i];
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        auto l_i = lower_bound(a.begin() + 1, a.end(), l) - a.begin();
        auto r_i = upper_bound(a.begin() + 1, a.end(), r) - a.begin();
        
        // Adjust indices for 1-based to 0-based conversion and handling edge cases
        if (l_i > n || r_i <= l_i) {
            cout << 0 << endl;  // No valid indices found, return 0
        } else if (r_i == n + 1) {
            cout << c[n] - c[l_i - 1] << endl;
        } else {
            cout << c[r_i - 1] - c[l_i - 1] << endl;
        }
    }
    return 0;
}