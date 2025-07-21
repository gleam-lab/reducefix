#include<bits/stdc++.h>
using namespace std;
int n, q;
int x[200005], p[200005];
long long sum[200005]; // Using long long to prevent overflow

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i]; // Cumulative sum
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        // Find the first x[i] >= L
        int c = lower_bound(x + 1, x + n + 1, L) - x;
        // Find the first x[i] > R
        int d = upper_bound(x + 1, x + n + 1, R) - x;
        cout << sum[d - 1] - sum[c - 1] << endl;
    }
    return 0;
}