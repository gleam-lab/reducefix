#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, q, x[N], p[N];
long long sum[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int l = lower_bound(x + 1, x + n + 1, L) - x;
        int r = upper_bound(x + 1, x + n + 1, R) - x;
        if (l <= r && r <= n) { // Ensure the range is valid
            cout << sum[r] - sum[l - 1] << endl;
        } else {
            cout << "Invalid range" << endl; // Handle invalid ranges gracefully
        }
    }
    return 0;
}