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
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        c[i] = c[i - 1] + b[i];
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        // Find the position of the first element in a[] >= l
        auto l_i = lower_bound(a.begin() + 1, a.end(), l) - a.begin();
        // Find the position of the first element in a[] > r
        auto r_j = upper_bound(a.begin() + 1, a.end(), r) - a.begin();
        
        // Since we are using 1-based indexing for input, we need to adjust for 0-based index
        // Also, if l_i points to beyond the last element, it means no element in a[] is >= l
        // Similarly, if r_j points to beyond the last element, it means no element in a[] is > r
        if (l_i > n || r < a[l_i]) {
            // If no valid left bound is found or the range is completely out of bounds
            cout << 0 << endl;
        } else if (r >= a[n]) {
            // If r is greater than or equal to the largest element in a[]
            cout << c[n] - c[l_i - 1] << endl;
        } else {
            // General case where both bounds are within valid range
            cout << c[r_j - 1] - c[l_i - 1] << endl;
        }
    }
    return 0;
}