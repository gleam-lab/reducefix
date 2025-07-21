#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int n, q, x[MAXN], p[MAXN], sum[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    sum[0] = 0; // Initialize the sum array with 0 for the first element
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i]; // Correctly accumulate the sums
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int l = lower_bound(x + 1, x + n + 1, L) - x;
        int r = upper_bound(x + 1, x + n + 1, R) - x;
        cout << sum[r - 1] - sum[l - 1] << endl;
    }
    return 0;
}