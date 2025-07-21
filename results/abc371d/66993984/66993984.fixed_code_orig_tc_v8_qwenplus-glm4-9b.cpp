#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
map<int, int> sum;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int c = lower_bound(x + 1, x + n + 1, L) - x; // Convert to 0-based index
        int d = upper_bound(x + 1, x + n + 1, R) - x - 1; // Convert to 0-based index and subtract 1
        if (c > d) {
            cout << "0\n"; // Handle cases where the range is invalid
        } else {
            cout << sum[d] - sum[c - 1] << endl; // Corrected the output calculation
        }
    }
    return 0;
}