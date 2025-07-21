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
        auto l_i = lower_bound(a.begin() + 1, a.begin() + n + 1, l) - a.begin();
        auto r_j = upper_bound(a.begin() + 1, a.begin() + n + 1, r) - a.begin();
        
        // Adjust for 1-based indexing and potential out-of-bounds for upper_bound
        if (r_j > n) r_j = n;
        
        // Calculate the sum of b[i] for indices i such that a[i] is in the range [l, r)
        ll result;
        if (l_i > 0 && a[l_i] <= r) {
            result = c[r_j - 1] - c[l_i - 1];
        } else {
            result = 0;  // No valid indices found in the specified range
        }
        
        cout << result << endl;
    }
    return 0;
}