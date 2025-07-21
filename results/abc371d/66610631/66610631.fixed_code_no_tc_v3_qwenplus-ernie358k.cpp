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
        
        // Adjust indices to be 0-based for array access
        l_i--;
        r_i--;
        
        // Handle edge cases where the bounds are out of array range
        if (l_i < 0 || r_i >= n) {
            // If both are out of range, it means the range covers the entire array
            if (l_i < 0 && r_i >= n) {
                cout << c[n] << endl;
            } 
            // If left bound is out of range, take from start to right bound
            else if (l_i < 0) {
                cout << c[r_i + 1] << endl;
            } 
            // If right bound is out of range, take from left bound to end
            else {
                cout << (c[n] - c[l_i]) << endl;
            }
        } else {
            // Normal case where both bounds are within array range
            cout << (c[r_i + 1] - c[l_i]) << endl;
        }
    }
    return 0;
}