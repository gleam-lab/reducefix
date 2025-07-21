#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
long long sum[200005]; // Use long long to prevent overflow

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i]; // Compute prefix sum
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        // Find the first x[i] >= l
        int left = lower_bound(x + 1, x + n + 1, l) - x;
        // Find the first x[i] > r
        int right = upper_bound(x + 1, x + n + 1, r) - x;
        // The sum is sum[right - 1] - sum[left - 1]
        cout << sum[right - 1] - sum[left - 1] << endl;
    }
    return 0;
}