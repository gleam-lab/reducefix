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
        // Initialize sum[i] with 0 before adding p[i]
        sum[i] = 0;
        // Ensure sum[i] contains the cumulative sum up to index i
        sum[i] = sum[i - 1] + p[i];
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        auto left = lower_bound(x + 1, x + n + 1, L) - x;
        auto right = upper_bound(x + 1, x + n + 1, R) - x;
        // Output the difference between the cumulative sums
        cout << sum[right - 1] - sum[left - 1] << endl;
    }
    return 0;
}