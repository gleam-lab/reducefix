#include<bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005];
long long sum[200005];  // Use long long to prevent overflow

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];  // Prefix sum calculation
    }

    cin >> q;
    while(q--) {
        int L, R;
        cin >> L >> R;

        // Find first index where x[i] >= L
        int left = lower_bound(x + 1, x + n + 1, L) - x;
        // Find first index where x[i] > R
        int right = upper_bound(x + 1, x + n + 1, R) - x;

        if(left < right) {
            cout << sum[right - 1] - sum[left - 1] << "\n";
        } else {
            cout << 0 << "\n";  // No elements in range
        }
    }

    return 0;
}