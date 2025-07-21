#include<bits/stdc++.h>
using namespace std;
int n, q;
long long x[200005], p[200005], sum[200005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    sum[0] = 0; // Initialize the first element of sum to 0
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int c = lower_bound(x + 1, x + n + 1, L) - x - 1; // Adjusted to 0-based index
        int d = upper_bound(x + 1, x + n + 1, R) - x - 1; // Adjusted to 0-based index
        cout << sum[d] - sum[c] << endl;
    }
    return 0;
}