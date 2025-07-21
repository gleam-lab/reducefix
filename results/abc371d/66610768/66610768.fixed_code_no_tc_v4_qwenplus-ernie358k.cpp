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
        auto r_j = upper_bound(a.begin() + 1, a.end(), r) - a.begin();
        
        // Handle edge case where `l` is less than the smallest element in `a`
        if (l_i == 0) l_i = 1; // No valid left index found, start from the first element
        
        // Handle edge case where `r` is greater than or equal to the largest element in `a`
        if (r >= a[n]) {
            cout << c[n] - c[l_i - 1] << endl;
        } else {
            cout << c[r_j - 1] - c[l_i - 1] << endl;
        }
    }
    return 0;
}