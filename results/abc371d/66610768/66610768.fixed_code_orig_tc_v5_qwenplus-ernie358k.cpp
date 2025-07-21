#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

int main() {
    int n, m;
    cin >> n;
    vector<ll> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = c[i - 1] + b[i];
    }
    cin >> m;
    while (m--) {
        ll l, r;
        cin >> l >> r;
        auto l_i = lower_bound(a.begin() + 1, a.end(), l) - a.begin();
        auto r_j = upper_bound(a.begin() + 1, a.end(), r) - a.begin();
        
        // Handle edge cases where l or r are out of bounds relative to a
        if (l_i == 0) l_i = 1; // If l is smaller than all elements in a, start from the first element
        if (r_j > n) r_j = n + 1; // If r is larger than all elements in a, end after the last element

        ll result;
        if (r >= *max_element(a.begin() + 1, a.end())) {
            // If r is greater than or equal to the maximum element in a, sum from l_i to the end
            result = c[n] - c[l_i - 1];
        } else {
            // Otherwise, sum from l_i to r_j-1
            result = c[r_j - 1] - c[l_i - 1];
        }
        cout << result << endl;
    }
    return 0;
}