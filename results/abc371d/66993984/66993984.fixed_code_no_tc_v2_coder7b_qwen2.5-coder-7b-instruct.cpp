#include<bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005];
long long sum[200005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i]; // Corrected variable name from 'sum' to 'sum[i]'
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        auto it1 = lower_bound(x + 1, x + n + 1, L); // Finds the first element not less than L
        auto it2 = upper_bound(x + 1, x + n + 1, R); // Finds the first element greater than R
        if (it1 != x + n + 1 && *it1 == L) { // Adjust index if exact match found
            cout << sum[it2 - x - 1] - sum[it1 - x - 1] << endl;
        } else {
            cout << sum[it2 - x - 2] - sum[it1 - x] << endl;
        }
    }

    return 0;
}