#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005], sum[2000005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        sum[i + 1] = sum[i] + p[i];  // Adjust index for 1-based array
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int l = lower_bound(x, x + n, L) - x;
        int r = upper_bound(x, x + n, R) - x;
        cout << sum[r] - sum[l] << endl;
    }
}