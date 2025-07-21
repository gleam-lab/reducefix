#include<bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005];
map<int, int> sum;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        auto it1 = lower_bound(x + 1, x + n + 1, L);
        auto it2 = upper_bound(x + 1, x + n + 1, R);

        int c = distance(x + 1, it1);
        int d = distance(x + 1, it2) - 1;

        if (it1 == x + n + 1 || *it1 > R) --d; // Adjust if exact match is not found
        if (it2 == x + n + 1 || *it2 < L) ++c; // Adjust if exact match is not found

        cout << sum[d] - sum[c] << endl;
    }
}