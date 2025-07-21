#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
int sum[2000005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] += sum[i - 1] + p[i];
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int l = lower_bound(x + 1, x + n + 1, L) - (x + 1) + 1; // +1 to convert iterator to index
        int r = upper_bound(x + 1, x + n + 1, R) - (x + 1); // no +1 needed here as upper_bound returns the past-the-end iterator
        if (l > r) {
            cout << "0\n";
        } else {
            cout << sum[r - 1] - sum[l - 2] << endl; // -1 to convert back to 0-based index
        }
    }
}