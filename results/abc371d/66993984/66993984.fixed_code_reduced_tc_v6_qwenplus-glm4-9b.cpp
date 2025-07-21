#include<bits/stdc++.h>
using namespace std;
int n, q;
long long x[200005], p[200005];
long long sum[200005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        sum[i] = sum[i - 1] + p[i];  // This line should accumulate the prefix sum correctly
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];  // Update the prefix sum array
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int c = lower_bound(x + 1, x + n + 1, L) - x;
        int d = upper_bound(x + 1, x + n + 1, R) - x;
        // Calculate the sum of products using the prefix sum array
        cout << sum[d - 1] - sum[c - 1] << endl;
    }
}