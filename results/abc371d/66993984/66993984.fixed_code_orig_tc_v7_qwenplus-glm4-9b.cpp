#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
long long sum[200005]; // Use long long to avoid overflow

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        sum[i + 1] = sum[i] + p[i]; // Sum starts at index 1, so use i+1
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int c = lower_bound(x, x + n, L) - x; // 0-indexed array
        int d = upper_bound(x, x + n, R) - x; // 0-indexed array
        cout << sum[d] - sum[c] << endl; // Correct the prefix sum indices
    }
    return 0;
}